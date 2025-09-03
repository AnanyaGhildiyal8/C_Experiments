#include<stdio.h>
void main()
{ int a,i=1,fact=1;
printf("\n Enter The Number:");
scanf("%d",&a);
while(i<=a)
{fact=fact*i;
    i=i+1;
}
 printf("The Factorial of %d is %d",a,fact);
 return 0;
}
