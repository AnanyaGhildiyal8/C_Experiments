#include<stdio.h>
int main ()
{ 
    int a,b,even=0,odd=0;
    printf("enter any two numbers");
    scanf("%d %d",&a,&b);
    if(a%2==0)
    { even=a*a;
        printf("%d",even);
    }
    if(b%2==0)
    { even=b*b;
        printf("%d",even);
    }
    if(a%2!=0)
    { odd=a*a*a;
        printf("%d",odd);
    }
    if(b%2!=0)
    { odd=b*b*b;
        printf("%d",odd);
    }
    return 0;
}