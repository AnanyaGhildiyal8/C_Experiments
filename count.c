#include<stdio.h>
int main()
{ char str[200];
    int i=0, x=1;

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') 
    {
        if (str[i] == ' ' || str[i] == '\n')
            x++;
        i++;
    }

    printf("Total words = %d\n", x);
    return 0;
}