#include<stdio.h>

float add(int, int);
float multiply(int,int);
float divide(int,int);
float subtract(int,int);

int main() {
    int a, b;
    float (*operation[4])(int, int);

    operation[0] = add;
    operation[1] = subtract;
    operation[2] = multiply;
    operation[3] = divide;
    
    printf("Enter two values ");
    scanf("%d%d", &a, &b);
    
    float result = (*operation[0])(a, b);
    printf("Addition (a+b) = %.1f\n", result);
    
    result = (*operation[1])(a, b);
    printf("Subtraction (a-b) = %.1f\n", result);
    
    result = (*operation[2])(a, b);
    printf("Multiplication (a*b) = %.1f\n", result);
    
    result = (*operation[3])(a, b);
    printf("Division (a/b) = %.1f\n", result);
    
    return 0;
}

float add(int a, int b) {
    return a + b;
}

float subtract(int a, int b) {
    return a - b;
}

float multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return a / (b * 1.0);
}
