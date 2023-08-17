#include <stdio.h>

void swap(int *, int *);

int main(void) {
    int a, b;
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    
    swap(&a, &b);

    printf("var1 = %d, var2 = %d\n", a, b);
    return 0;
}

void swap(int *ptr1, int *ptr2) {
    int temp;
    temp = *ptr1; *ptr1 = *ptr2; *ptr2 = temp;
}