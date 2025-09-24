#include<stdio.h>
int main()
{ char str[200];
    int i=0, a= 0,d=0,s=0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            a++;
        else if (str[i] >= '0' && str[i] <= '9')
            d++;
        else if (str[i] != '\n' && str[i] != ' ')
            s++;
        i++;
    }

    printf("Alphabets = %d\n", a);
    printf("Digits = %d\n", d);
    printf("Special = %d\n", s);
    return 0;

}