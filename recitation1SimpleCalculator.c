// Online C compiler to run C program online
#include <stdio.h>

int main() {
    char op;
    printf("Enter an operator (+, -, *, / or q to quit): ");
    scanf("%c", &op);
    if (op == '+' || op == '-' || op == '*' || op == '/') {
        float n1, n2;
        printf("Input Floating Point Number 1: ");
        scanf("%f", &n1);
        printf("Input Floating Point Number 2: ");
        scanf("%f", &n2);
        switch (op) {
            case '+':
                printf("Result: %0.2f", n1 + n2);
                return 0;
            case '-':
                printf("Result: %0.2f", n1 - n2);
                return 0;
            case '*':
                printf("Result: %0.2f", n1 * n2);
                return 0;
            case '/':
                printf("Result: %0.2f", n1 / n2);
                return 0;
        }
    } else {
        if (op == 'q') {
            printf("Bye!");
            return 0;
        } else {
            printf("Unrecognised operation\n");
            return 0;
        }
    }
    return 0;
}