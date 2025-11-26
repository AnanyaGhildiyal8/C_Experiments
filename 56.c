#include <stdio.h>

int main() {
    char s[200];
    int len = 0;

    scanf("%[^\n]", s);

    while (s[len] != '\0') len++;

    printf("%d", len);
    return 0;
}
