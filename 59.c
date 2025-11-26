#include <stdio.h>

int main() {
    char s1[200], s2[200];
    int i = 0;

    scanf("%s %s", s1, s2);

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            printf("Not Equal");
            return 0;
        }
        i++;
    }

    if (s1[i] == s2[i]) printf("Equal");
    else printf("Not Equal");

    return 0;
}