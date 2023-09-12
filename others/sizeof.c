#include <stdio.h>

int func(int* arr);
int func1(char* arr);
int func2(float* arr);


int main(void) {
    int arrLocal[5] = {0,0,0,0,0};
    char arrLocal1[5] = "abcde";
    float arrLocal2[5] = {1.0,2.0,3.0,4.0,5.0};
    printf("sizeof intLocal   : %lu\n", sizeof(arrLocal));
    printf("sizeof intFunction: %d\n", func(arrLocal));

    printf("sizeof charLocal   : %lu\n", sizeof(arrLocal1));
    printf("sizeof charFunction: %d\n", func1(arrLocal1));

    printf("sizeof floatLocal   : %lu\n", sizeof(arrLocal2));
    printf("sizeof floatFunction: %d\n", func2(arrLocal2));
}

int func(int* arr) {
    return sizeof(arr);
}

int func1(char* arr) {
    return sizeof(arr);
}

int func2(float* arr) {
    return sizeof(arr);
}