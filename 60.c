#include <stdio.h>

int main() {
    char s[300];
    int count = 1;

    scanf("%[^\n]", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0')
            count++;
    }

    printf("%d", count);
    return 0;
}