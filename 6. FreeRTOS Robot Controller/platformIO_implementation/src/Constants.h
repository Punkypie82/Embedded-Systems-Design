// MQ2 Gas Sensor Pin(s)
#define MQ2_PIN A0

// SR04 Ultrasonic Sensor Pin(s)
#define PIN_TRIG A1
#define PIN_ECHO A2

// Wheel Stepper Motor Pin(s)
#define MOTOR_B_NEG 10
#define MOTOR_B_POS 11
#define MOTOR_A_POS 12
#define MOTOR_A_NEG 13

// Wheel Stepper Motor Constants
#define MOTOR_MAX_SPEED 200
#define MOTOR_ACCELLERATION 100000

// Fan Stepper Motor Pin(s)
#define FAN_B_NEG 2
#define FAN_B_POS 3
#define FAN_A_POS 4
#define FAN_A_NEG 5

// Fan Stepper Motor Constants
#define FAN_MAX_SPEED 100000
#define FAN_ACCELLERATION 100000
#define FAN_GAIN 2

// Constants
#define M_INF 999999

// Gas Sensor Constants (f(x(t)) = ax(t) + b)
#define A 0.000390625
#define B 4.277343756
#define PPM_THRESHOLD 550

// Ultrasonic Sensor Read Interval
#define SENSOR_READ_INT 250

// // Input Signals
// unsigned int PPM;
// unsigned int DISTANCE;

// // Output Signals
// unsigned int MOTOR;
// unsigned int FAN;