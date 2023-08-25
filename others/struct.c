#include <stdio.h>

typedef struct {
    float horsepower;
    float consumption;
} engine;

typedef struct {
    engine engine;
    int wheels;
} car;

int main(void) {
    engine V1 = {1000.7, 50.5};
    car ferarri = {V1, 4};
    printf("engine %f\n", ferarri.engine.horsepower);

    return 0;
}
