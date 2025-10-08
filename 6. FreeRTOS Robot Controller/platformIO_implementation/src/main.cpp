#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <AccelStepper.h>
#include <semphr.h>
extern "C" {
  #include "Controller.h"
  #include "Constants.h"
}

int ppm( int adc_input );
void TaskReadPPM( void *pvParameters );
void TaskReadDist( void *pvParameters );
void TaskControlSig( void *pvParameters );
void TaskSignalMotor( void *pvParameters );
void TaskSignalFan( void *pvParameters );

AccelStepper motor_stepper(AccelStepper::FULL4WIRE, MOTOR_B_NEG, MOTOR_B_POS, MOTOR_A_POS, MOTOR_A_NEG);
AccelStepper fan_stepper(AccelStepper::FULL4WIRE, FAN_B_NEG, FAN_B_POS, FAN_A_POS, FAN_A_NEG);

SemaphoreHandle_t xStepperMutex;

void setup() {
  Serial.begin(115200);

  // Semaphore to Control Stepper Motors Precedence Problem
  xStepperMutex = xSemaphoreCreateMutex();

  // Task to Read PPM Value From MQ2 Gas Sensor
  xTaskCreate( TaskReadPPM, "ReadPPM", 64, NULL, 4, NULL );
  // Task to Read Distance Value From SR04 Ultrasonic Sensor
  xTaskCreate( TaskReadDist, "ReadDistance", 64, NULL, 4, NULL );
  // Use Generated Model to Calculate Control Signals
  xTaskCreate( TaskControlSig, "CalculateControlSignals", 96, NULL, 4, NULL );
  // Signal the Motor to Move
  xTaskCreate( TaskSignalMotor, "MotorSignal", 128, NULL, 3, NULL );
  // Signal the Fan to Move
  xTaskCreate( TaskSignalFan, "FanSignal", 128, NULL, 3, NULL );
}

void loop() {
}

int ppm(int adc_input) {
  float voltage = ((float)adc_input/1024) * 5;
  float ppm_val = (voltage - B) / A;
  return (int)ppm_val;
}

void TaskReadPPM(void *pvParameters) {
  (void) pvParameters;

  // Configure MQ2_Sensor
  pinMode(MQ2_PIN, INPUT);

  for (;;) {
    // Read PPM Levels Using MQ2 Sensor
    int mq2_val = analogRead(MQ2_PIN);
    int ppm_val = ppm(mq2_val);
    rtU.ppm = ppm_val;

    vTaskDelay( SENSOR_READ_INT / portTICK_PERIOD_MS );
    taskYIELD();
  }
}

void TaskReadDist(void *pvParameters) {
  (void) pvParameters;

  // Configure Distance_Sensor
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  for (;;) {
    // Read Distance to Leak Every SENSOR_READ_INT Milliseconds
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    int duration = pulseIn(PIN_ECHO, HIGH);
    int distance = duration / 58;
    rtU.distance = distance;

    vTaskDelay( SENSOR_READ_INT / portTICK_PERIOD_MS );
    taskYIELD();
  }
}

void TaskControlSig(void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    // Set Max Safe Gas Levels
    rtU.threshold = PPM_THRESHOLD;
    
    // Run The Controll Unit on New Data
    Controller_step();
    vTaskDelay( 10 / portTICK_PERIOD_MS );
    taskYIELD();
  }
}

void TaskSignalMotor(void *pvParameters) {
  (void) pvParameters;

  motor_stepper.setMaxSpeed(MOTOR_MAX_SPEED);
  motor_stepper.setAcceleration(MOTOR_ACCELLERATION);

  for (;;) {
    if (xSemaphoreTake(xStepperMutex, portMAX_DELAY) == pdTRUE) {
      motor_stepper.setSpeed(MOTOR_MAX_SPEED * rtY.motor);
      motor_stepper.runSpeed();
      xSemaphoreGive(xStepperMutex);
    }
    vTaskDelay(1 / portTICK_PERIOD_MS);
    taskYIELD();
  }
}

void TaskSignalFan(void *pvParameters) {
  (void) pvParameters;

  fan_stepper.setMaxSpeed(FAN_MAX_SPEED);
  fan_stepper.setAcceleration(FAN_ACCELLERATION);

  for (;;) {
    if (xSemaphoreTake(xStepperMutex, portMAX_DELAY) == pdTRUE) {
      fan_stepper.setSpeed(FAN_GAIN * rtU.ppm * rtY.fan);
      fan_stepper.runSpeed();
      xSemaphoreGive(xStepperMutex);
    }
    vTaskDelay(1 / portTICK_PERIOD_MS);
    taskYIELD();
  }
}