#include <Arduino.h>
#include <stdio.h>
#define DATALEN 15
#define FILTERTAPS 5

double x[DATALEN] = { 128.0, 130.0, 180.0, 140.0, 120.0,
                      110.0, 107.0, 103.5, 102.0, 90.0,
                      84.0, 70.0, 30.0, 77.3, 95.7 };
const double h[FILTERTAPS] = {0.125,-0.25,0.5,-0.25,0.125};
double y[DATALEN];

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
  int i,n;
  for(i=0;i<DATALEN;++i) {
    y[i] = 0;
    for(n=0; n < FILTERTAPS; ++n)
      if ((i - n) >= 0) 
        y[i] += h[n]*x[i-n];
  }
  // for(i = 0; i < DATALEN; ++i) 
  //   Serial.println(y[i], 2);
  return 0;
}