#include<stdio.h>
#include<string.h>
float bucket = 0; 
void catalog()
{   int choice2;
    printf("=======CATALOG=======\n");
    printf("1.Apples\n");
    printf("2.Milk\n");
    printf("3.Bread\n");
    printf("4.Eggs\n");
    printf("5.Chicken\n");
    printf("====================\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice2);
    
    switch(choice2)
    {
        case 1:
            printf("You have selected Apples\n");
            bucket = bucket + 50;
            break;
        case 2:
            printf("You have selected Milk\n");
            bucket = bucket + 30;
            break;
        case 3:
            printf("You have selected Bread\n");
            bucket = bucket + 20;
            break;
        case 4:
            printf("You have selected Eggs\n");
            bucket = bucket + 10;
            break;
        case 5:
            printf("You have selected Chicken\n");
            bucket = bucket + 150;
            break;
        default:
            printf("Invalid Choice\n");
    }
}

int main()
{  
    int choice;
    char username[20];
    char password[20];
    char username2[20];
    char password2[20];
    char buyMore;
    
    printf("1. Signin\n");
    printf("2. Login\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    if(choice == 1){
        printf("Enter your User Name: ");
        scanf("%s",username);
        printf("Enter Password: ");
        scanf("%s",password);
        printf("Registration successful! Please login now.\n");
    }
    
    if (choice == 1 || choice == 2)
    { 
        printf("Enter your username: ");
        scanf("%s",username2);
        printf("Enter your password: ");
        scanf("%s",password2);
        
        if (strcmp(username, username2) == 0 && strcmp(password, password2) == 0)
        { 
            printf("Login successful!\n");
            
            do {
                catalog();
                printf("Do you want to buy more? (Y/N): ");
                scanf(" %c", &buyMore); 
            } while(buyMore == 'Y' || buyMore == 'y');
            static int orderNumber = 1000;
            printf("\n===== BILL =====\n");
            printf("Order Number: %d\n", orderNumber++);
            printf("Subtotal: $%.2f\n", bucket);
            float tax = bucket * 0.07;
            printf("Tax (7%%): $%.2f\n", tax);
            float total = bucket + tax;
            printf("Total: $%.2f\n", total);
            printf("================\n");
        }
        else
        {
            printf("Invalid username or password!\n");
        }
    }
    
    return 0;
}