#include <stdio.h>
int main() 
{int x= 0,y=1,a;
    printf("Enter a number: ");
    scanf("%d", &a);
    while (y<a) 
    { int temp =y;
        y=x+y;
        a=temp;
    }
    if(a==y || a==0)
        printf("%d is a part of the Fibonacci series.\n",a);
    else
        printf("%d is not a part of the Fibonacci series.\n",a);
    return 0;
}