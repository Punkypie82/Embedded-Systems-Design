#include <Arduino.h>
#include <stdio.h>

#define DATALEN 15
#define FILTERTAPS 5

double x[DATALEN] = { 128.0, 130.0, 180.0, 140.0, 120.0,
                      110.0, 107.0, 103.5, 102.0, 90.0,
                      84.0, 70.0, 30.0, 77.3, 95.7 };

double y[DATALEN];

const double h0 =  0.125;
const double h1 = -0.25;
const double h2 =  0.5;
const double h3 = -0.25;
const double h4 =  0.125;

int func(void);

void setup() {
  Serial.begin(9600);

  // volatile unsigned long start = micros(); 
  unsigned long start = micros(); 
  func();
  unsigned long end = micros();
  // volatile unsigned long end = micros();

  Serial.print("Execution time (microseconds): ");
  Serial.println(end - start);
}

void loop() {}

int func(void) {
  double xi, xi1, xi2, xi3, xi4;

  // Process first 4 samples (boundary condition)
  for (int i = 0; i < 4; ++i) {
    double acc = 0.0;
    if (i >= 0) acc += h0 * x[i];
    if (i - 1 >= 0) acc += h1 * x[i - 1];
    if (i - 2 >= 0) acc += h2 * x[i - 2];
    if (i - 3 >= 0) acc += h3 * x[i - 3];
    if (i - 4 >= 0) acc += h4 * x[i - 4];
    y[i] = acc;
  }

  // Process main loop with no bounds checks
  for (int i = 4; i < DATALEN; ++i) {
    xi  = x[i];
    xi1 = x[i - 1];
    xi2 = x[i - 2];
    xi3 = x[i - 3];
    xi4 = x[i - 4];
    y[i] = h0 * xi + h1 * xi1 + h2 * xi2 + h3 * xi3 + h4 * xi4;
  }

  // for (int i = 0; i < DATALEN; ++i)
  //   Serial.println(y[i], 2);

  return 0;
}