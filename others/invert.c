#include <stdio.h>

int main (void) {
    u_int8_t num = 0b00000001;

    printf("num: \n");
    printf("%u\n", num);

    num = ~num; 
    u_int8_t new = !num;

    printf("num after ~: \n");
    printf("%u\n", num);

    printf("num after !: \n");
    printf("%u\n", new);

    return 0;
}