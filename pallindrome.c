#include<stdio.h>
int main()
{char str[200];
    int i = 0, j, len = 0, flag = 1;
   printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
 while (str[len] != '\0' && str[len] != '\n') 
 {
      j = len - 1;
 }
    while (i < j) 
    {
        if (str[i] != str[j]) 
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;

}