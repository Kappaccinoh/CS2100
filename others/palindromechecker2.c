#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int main(void) {
    char s[100];
    printf("enter a string: \n");
    fgets(s, 100, stdin);
    char *backward = s;
    int count = 0;

    while (*backward != '\0') {
        *backward = tolower(*backward);
        backward++;
        count++;
    }

    backward--;
    backward--;
    char *forward = s;

    // printf("forwards: %c\n", *forward);
    // printf("backwards: %c\n", *backward);

    for (int i = 0; i < count - 1; i++) {
        if (*forward != *backward) {
            // printf("forwards: %c\n", *forward);
            // printf("backwards: %c\n", *backward);
            printf("NO this is not a palindrome\n");
            return 0;
        }
        backward--;
        forward++;
    }
    printf("YES this is a palindrome");
    return 0;
}
