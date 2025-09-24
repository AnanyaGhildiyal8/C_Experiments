#include<stdio.h>
int main()
{
    char str[200];
    int i = 0, start = 0, maxLen = 0, wordStart = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (1) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') {
            int wordLen = i - start;
            if (wordLen > maxLen) {
                maxLen = wordLen;
                wordStart = start;
            }
            start = i + 1;
        }
        if (str[i] == '\0' || str[i] == '\n')
            break;
        i++;
    }

    printf("Longest word: ");
    for (i = wordStart; i < wordStart + maxLen; i++)
        putchar(str[i]);
    printf("\nLength: %d\n", maxLen);

    return 0;

}