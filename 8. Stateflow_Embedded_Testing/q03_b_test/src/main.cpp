#include <Arduino.h>
extern "C" {
  #include "Chart.h"
}

#define PIN_START A0
#define PIN_STOP A1
#define PIN_T_ON A2
#define PIN_T_OFF A3
#define PIN_DEC A4
#define PIN_INC A5

#define PIN_SHUT 2
#define PIN_ON 3
#define PIN_OFF 4
#define PIN_A 5
#define PIN_B 6


void setup() {
  Serial.begin(115200);
  pinMode(PIN_START, INPUT);
  pinMode(PIN_STOP, INPUT);
  pinMode(PIN_T_ON, INPUT);
  pinMode(PIN_T_OFF, INPUT);
  pinMode(PIN_DEC, INPUT);
  pinMode(PIN_INC, INPUT);

  pinMode(PIN_SHUT, OUTPUT);
  pinMode(PIN_ON, OUTPUT);
  pinMode(PIN_OFF, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  rtU.start = digitalRead(PIN_START);
  rtU.stop = digitalRead(PIN_STOP);
  rtU.t_on = digitalRead(PIN_T_ON);
  rtU.t_off = digitalRead(PIN_T_OFF);
  rtU.dec = digitalRead(PIN_DEC);
  rtU.inc = digitalRead(PIN_INC);

  Chart_step();

  digitalWrite(PIN_SHUT, rtY.shut);
  digitalWrite(PIN_ON, rtY.on);
  digitalWrite(PIN_OFF, rtY.off);
  digitalWrite(PIN_A, rtY.a);
  digitalWrite(PIN_B, rtY.b);
  // Serial.print("shut: "); Serial.print(rtY.shut);
  // Serial.print(" | on: "); Serial.print(rtY.on);
  // Serial.print(" | off: "); Serial.print(rtY.off);
  // Serial.print(" | a: "); Serial.print(rtY.a);
  // Serial.print(" | b: "); Serial.println(rtY.b);
}

