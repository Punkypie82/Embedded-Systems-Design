#include <Arduino.h>
#include <stdio.h>

double x[15] = { 128.0, 130.0, 180.0, 140.0, 120.0,
                 110.0, 107.0, 103.5, 102.0, 90.0,
                 84.0, 70.0, 30.0, 77.3, 95.7 };

double y[15];

int func(void);

void setup() {
  Serial.begin(9600);

  unsigned long start = micros();
  func();
  unsigned long end = micros();

  Serial.print("Execution time (microseconds): ");
  Serial.println(end - start);
}

void loop() {}

int func(void) {
  int i;
  for (i = 0; i < 15; ++i) {
    y[i] = 0;

    if (i >= 0)
      y[i] += 0.125 * x[i];
    if (i >= 1)
      y[i] += -0.25 * x[i - 1];
    if (i >= 2)
      y[i] += 0.5 * x[i - 2];
    if (i >= 3)
      y[i] += -0.25 * x[i - 3];
    if (i >= 4)
      y[i] += 0.125 * x[i - 4];
  }

  // for (i = 0; i < 15; ++i)
  //   Serial.println(y[i], 2);

  return 0;
}
