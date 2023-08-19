#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int strLength(char str[]);

int main(void) {
    char s[100];
    printf("Enter a string (it may contain spaces and mixed capitalization):\n");
    fgets(s, 100, stdin);

    int forward = 0;
    int backward = strLength(s) - 1;

    for (int i = 0; i < strLength(s); i++) {
        s[i] = tolower(s[i]);
    }

    // printf("%s\n", s);
    char is[100];
    for (int i = backward; i >= 0; i--) {
        is[forward] = s[i];
        forward++;
    }

    // printf("%s\n", is);

    for (int i = 0; i < strLength(s); i++) {
        if (s[i] != is[strLength(s) - 1 - i]) {
            printf("NO it is not a palindrome\n");
            return 0;
        }
    }
    printf("YES it is a palindrome\n");
    return 0;
}

int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
