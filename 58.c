#include <stdio.h>
#include <string.h>

int main() {
    char s[200];
    scanf("%[^\n]", s);

    int i = 0, j = strlen(s) - 1;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("%s", s);
    return 0;
}
