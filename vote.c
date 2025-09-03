#include<stdio.h>
int main()
{ int x=0,y=0,z=0,a;
  char l;
    printf("enter 1 for x");
    printf("enter 2 for y");
    printf("enter 3 for z");
    printf("enter your vote");
    scanf("%d",&a);
    printf("your choice is %d",a);
    switch(a)
    {
    case 1:
    x+=1;
    printf("for candidate %d",x);
    break;
    case 2:
    y+=1;
    printf("for candidate %d",y);
    break;
    case 3:
    z+=1;
    printf("for candidate %d",z);
    break;
    default:
    printf("wrong choice");
    }
    printf("do you wanna enter more values(y/n)");
    scanf(" %c",&l);
    while(l=='y'||l=='Y')
    {printf("enter your vote");
    scanf("%d",&a);
    printf("your choice is %d",a);}
{printf("thanks for voting!");
    }
}
