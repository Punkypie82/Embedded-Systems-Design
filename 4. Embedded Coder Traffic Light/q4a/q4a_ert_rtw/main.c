#include <stdio.h>
#include "q4a.h"

int main() {
    q4a_initialize();

    printf("Enter A: ");
    scanf("%f", &rtU.In1);
    printf("Enter B: ");
    scanf("%f", &rtU.In2);

    q4a_step();

    printf("Output(A+B): %f\n", rtY.Out1);

    return 0;
}
