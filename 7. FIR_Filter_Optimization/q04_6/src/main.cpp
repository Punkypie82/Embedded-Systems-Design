#include <Arduino.h>
#include <stdio.h>

typedef short fixed_point;

fixed_point float_to_fixed(double input);
double fixed_to_float(fixed_point input);

inline fixed_point float_to_fixed(double input)
{
    return (fixed_point)(round(input * (1 << 5)));
}

inline double fixed_to_float(fixed_point input)
{
    return ((double)input / (double)(1 << 5));
}

double x[15] = { 128.0, 130.0, 180.0, 140.0, 120.0,
                 110.0, 107.0, 103.5, 102.0, 90.0,
                 84.0, 70.0, 30.0, 77.3, 95.7 };
const double h[5] = {0.125,-0.25,0.5,-0.25,0.125};
double y[15];
fixed_point acc[15];

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
  for (i = 0; i < 15; i=i+5) {
    acc[i] = 0;
    acc[i+1] = 0;
    acc[i+2] = 0;
    acc[i+3] = 0;
    acc[i+4] = 0;

    if (i >= 0)
      acc[i] += float_to_fixed(0.125 * x[i]);
    if (i >= 1)
      acc[i] += float_to_fixed(-0.25 * x[i - 1]);
    if (i >= 2)
      acc[i] += float_to_fixed(0.5 * x[i - 2]);
    if (i >= 3)
      acc[i] += float_to_fixed(-0.25 * x[i - 3]);
    if (i >= 4)
      acc[i] += float_to_fixed(0.125 * x[i - 4]);


    if (i+1 >= 0)
      acc[i+1] += float_to_fixed(0.125 * x[i+1]);
    if (i+1 >= 1)
      acc[i+1] += float_to_fixed(-0.25 * x[i+1 - 1]);
    if (i+1 >= 2)
      acc[i+1] += float_to_fixed(0.5 * x[i+1 - 2]);
    if (i+1 >= 3)
      acc[i+1] += float_to_fixed(-0.25 * x[i+1 - 3]);
    if (i+1 >= 4)
      acc[i+1] += float_to_fixed(0.125 * x[i+1 - 4]);


    if (i+2 >= 0)
      acc[i+2] += float_to_fixed(0.125 * x[i+2]);
    if (i+2 >= 1)
      acc[i+2] += float_to_fixed(-0.25 * x[i+2 - 1]);
    if (i+2 >= 2)
      acc[i+2] += float_to_fixed(0.5 * x[i+2 - 2]);
    if (i+2 >= 3)
      acc[i+2] += float_to_fixed(-0.25 * x[i+2 - 3]);
    if (i+2 >= 4)
      acc[i+2] += float_to_fixed(0.125 * x[i+2 - 4]);


    if (i+3 >= 0)
      acc[i+3] += float_to_fixed(0.125 * x[i+3]);
    if (i+3 >= 1)
      acc[i+3] += float_to_fixed(-0.25 * x[i+3 - 1]);
    if (i+3 >= 2)
      acc[i+3] += float_to_fixed(0.5 * x[i+3 - 2]);
    if (i+3 >= 3)
      acc[i+3] += float_to_fixed(-0.25 * x[i+3 - 3]);
    if (i+3 >= 4)
      acc[i+3] += float_to_fixed(0.125 * x[i+3 - 4]);


    if (i+4 >= 0)
      acc[i+4] += float_to_fixed(0.125 * x[i+4]);
    if (i+4 >= 1)
      acc[i+4] += float_to_fixed(-0.25 * x[i+4 - 1]);
    if (i+4 >= 2)
      acc[i+4] += float_to_fixed(0.5 * x[i+4 - 2]);
    if (i+4 >= 3)
      acc[i+4] += float_to_fixed(-0.25 * x[i+4 - 3]);
    if (i+4 >= 4)
      acc[i+4] += float_to_fixed(0.125 * x[i+4 - 4]);

    y[i] = fixed_to_float(acc[i]);
    y[i+1] = fixed_to_float(acc[i+1]);
    y[i+2] = fixed_to_float(acc[i+2]);
    y[i+3] = fixed_to_float(acc[i+3]);
    y[i+4] = fixed_to_float(acc[i+4]);
  }

  // for(i = 0; i < 15; ++i) 
  //   Serial.println(y[i], 2);
  return 0;
}