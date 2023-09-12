#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union {
    float f;
    int32_t i;
} uFloat;

union {
    double d;
    int64_t i;
} uDouble;

int main(void) {
    char argv[100];

    scanf("%s", argv);

    float input = strtof(&argv[0], NULL);

    uFloat.f = input;
    uDouble.d = input;

    printf("u.f = %f => u.i = 0x%x\n", uFloat.f, uFloat.i);
    printf("u.f = %lf => u.i = 0x%llx\n", uDouble.d, uDouble.i);

}