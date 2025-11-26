#include <stdio.h>

int main() {
    char s[200];
    int v = 0, c = 0;

    scanf("%[^\n]", s);

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            char x = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
            if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') v++;
            else c++;
        }
    }

    printf("Vowels:%d Consonants:%d", v, c);
    return 0;
}
