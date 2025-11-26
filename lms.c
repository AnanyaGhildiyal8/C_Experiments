#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Book {
    char title[50];
    char author[50];
    char isbn[20];
    int available_copies;
};

struct Member {
    char name[50];
    char member_id[20];
    char contact[50];
};

struct IssueRecord {
    char member_id[20];
    char isbn[20];
    char issue_date[20];
    char return_date[20];
};

struct returnRecord {
    char member_id[20];
    char isbn[20];
    char return_date[20];
};

struct User {
    char username[20];
    char password[20];
};

// Global arrays
struct Book books[100];
int book_count = 0;

struct Member members[100];
int member_count = 0;

struct IssueRecord issues[100];
int issue_count = 0;

struct returnRecord returns[100];
int return_count = 0;

struct User users[100];
int user_count = 0;

// Simple validation functions
int isNumber(char *str) {
    for(int i=0; str[i]; i++) {
        if(!isdigit(str[i])) return 0;
    }
    return 1;
}

int isValidDate(char *date) {
    if(strlen(date) != 10) return 0;
    if(date[2] != '-' || date[5] != '-') return 0;
    return 1;
}

void addBook()
{ 
    if(book_count >= 100) {
        printf("Cannot add more books! Storage full.\n");
        return;
    }
    
    printf("Enter book title: ");
    getchar(); // Clear input buffer
    fgets(books[book_count].title, 50, stdin);
    books[book_count].title[strcspn(books[book_count].title, "\n")] = 0; // Remove newline
    
    printf("Enter book author: ");
    fgets(books[book_count].author, 50, stdin);
    books[book_count].author[strcspn(books[book_count].author, "\n")] = 0;
    
    printf("Enter book ISBN: ");
    scanf("%s", books[book_count].isbn);
    if(strlen(books[book_count].isbn) < 10) {
        printf("Error: ISBN must be at least 10 characters!\n");
        return;
    }
    
    printf("Enter available copies: ");
    if(scanf("%d", &books[book_count].available_copies) != 1 || books[book_count].available_copies < 0) {
        printf("Error: Copies must be a positive number!\n");
        return;
    }
    
    book_count++;
    printf("Book added successfully!\n");
}

void viewBooks()
{
    if (book_count==0)
    { 
        printf("No books found!\n");
        return;
    }
    printf("\n=== ALL BOOKS ===\n");
    for(int i=0;i<book_count;i++)
    { 
        printf("Title: %s\n",books[i].title);
        printf("Author: %s\n",books[i].author);
        printf("ISBN: %s\n",books[i].isbn);
        printf("Copies: %d\n\n",books[i].available_copies);
    }
}

void searchBook()
{
    char search_isbn[20];
    int found=0;
    printf("Enter ISBN to search:");    
    scanf("%s",search_isbn);
    if (book_count==0)
    {
        printf("No books found!\n");
        return;
    }
    for(int i=0;i<book_count;i++)
    {
        if (strcmp(books[i].isbn,search_isbn)==0)
        {
            printf("Book Found!\n");
            printf("Title: %s\n",books[i].title);
            printf("Author: %s\n",books[i].author);
            printf("ISBN: %s\n",books[i].isbn);
            printf("Copies: %d\n",books[i].available_copies);
            found=1;
        }
    }
    if (!found)
    {
        printf("Book with ISBN %s not found!\n",search_isbn);
    }
}

void deleteBook()
{
    char delete_isbn[20];
    int found=0;
    printf("Enter ISBN to delete:");
    scanf("%s",delete_isbn);
    if (book_count==0)
    {
        printf("No books found!\n");
        return;
    }
    for(int i=0;i<book_count;i++)
    {
        if (strcmp(books[i].isbn,delete_isbn)==0)
        {
            found=1;
            for(int j=i;j<book_count-1;j++)
            {
                books[j]=books[j+1];
            }
            book_count--;
            printf("Book with ISBN %s deleted successfully!\n",delete_isbn);
            break;
        }
    }
    if (!found)
    {
        printf("Book with ISBN %s not found!\n",delete_isbn);
    }
}

void addMember()
{
    if(member_count >= 100) {
        printf("Cannot add more members! Storage full.\n");
        return;
    }
    
    printf("Enter member name: ");
    getchar(); // Clear input buffer
    fgets(members[member_count].name, 50, stdin);
    members[member_count].name[strcspn(members[member_count].name, "\n")] = 0;
    
    printf("Enter member ID: ");
    scanf("%s", members[member_count].member_id);
    if(strlen(members[member_count].member_id) < 3) {
        printf("Error: Member ID must be at least 3 characters!\n");
        return;
    }
    
    printf("Enter contact info: ");
    getchar(); // Clear input buffer
    fgets(members[member_count].contact, 50, stdin);
    members[member_count].contact[strcspn(members[member_count].contact, "\n")] = 0;
    
    member_count++;
    printf("Member added successfully!\n");
}

void viewMembers()
{
    if (member_count==0)
    {
        printf("No members found!\n");
        return;
    }
    printf("\n=== ALL MEMBERS ===\n");
    for(int i=0;i<member_count;i++)
    {
        printf("Name: %s\n",members[i].name);
        printf("Member ID: %s\n",members[i].member_id);
        printf("Contact: %s\n\n",members[i].contact);
    }
}

void searchMember()
{
    char search_id[20];
    int found=0;
    printf("Enter Member ID to search:");
    scanf("%s",search_id);
    if (member_count==0)
    {
        printf("No members found!\n");
        return;
    }
    for(int i=0;i<member_count;i++)
    {
        if (strcmp(members[i].member_id,search_id)==0)
        {
            printf("Member Found!\n");
            printf("Name: %s\n",members[i].name);
            printf("Member ID: %s\n",members[i].member_id);
            printf("Contact: %s\n",members[i].contact);
            found=1;
        }
    }
    if (!found)
    {
        printf("Member with ID %s not found!\n",search_id);
    }
}

void deletemember()
{
    char delete_id[20];
    int found=0;
    printf("Enter Member ID to delete:");
    scanf("%s",delete_id);
    if (member_count==0)
    {
        printf("No members found!\n");
        return;
    }
    for(int i=0;i<member_count;i++)
    {
        if (strcmp(members[i].member_id,delete_id)==0)
        {
            found=1;
            for(int j=i;j<member_count-1;j++)
            {
                members[j]=members[j+1];
            }
            member_count--;
            printf("Member with ID %s deleted successfully!\n",delete_id);
            break;
        }
    }
    if (!found)
    {
        printf("Member with ID %s not found!\n",delete_id);
    }
}

void issueBook()
{
    if(issue_count >= 100) {
        printf("Cannot issue more books! Storage full.\n");
        return;
    }
    
    printf("Enter Member ID: ");
    scanf("%s",issues[issue_count].member_id);
    if(strlen(issues[issue_count].member_id) < 3) {
        printf("Error: Invalid Member ID!\n");
        return;
    }
    
    printf("Enter Book ISBN: ");
    scanf("%s",issues[issue_count].isbn);
    if(strlen(issues[issue_count].isbn) < 10) {
        printf("Error: Invalid ISBN!\n");
        return;
    }
    
    printf("Enter Issue Date (DD-MM-YYYY): ");
    scanf("%s",issues[issue_count].issue_date);
    if(!isValidDate(issues[issue_count].issue_date)) {
        printf("Error: Invalid date format! Use DD-MM-YYYY.\n");
        return;
    }
    
    printf("Enter Return Date (DD-MM-YYYY): ");
    scanf("%s",issues[issue_count].return_date);
    if(!isValidDate(issues[issue_count].return_date)) {
        printf("Error: Invalid date format! Use DD-MM-YYYY.\n");
        return;
    }

    issue_count++;
    printf("Book issued successfully!\n");
}

void returnBook()
{
    if(return_count >= 100) {
        printf("Cannot process more returns! Storage full.\n");
        return;
    }
    
    printf("Enter Member ID: ");
    scanf("%s",returns[return_count].member_id);
    if(strlen(returns[return_count].member_id) < 3) {
        printf("Error: Invalid Member ID!\n");
        return;
    }
    
    printf("Enter Book ISBN: ");
    scanf("%s",returns[return_count].isbn);
    if(strlen(returns[return_count].isbn) < 10) {
        printf("Error: Invalid ISBN!\n");
        return;
    }
    
    printf("Enter Return Date (DD-MM-YYYY): ");
    scanf("%s",returns[return_count].return_date);
    if(!isValidDate(returns[return_count].return_date)) {
        printf("Error: Invalid date format! Use DD-MM-YYYY.\n");
        return;
    }

    return_count++;
    printf("Book returned successfully!\n");
}

void viewIssuedBooks()
{
    if (issue_count == 0) {
        printf("No issued books found!\n");
        return;
    }
    printf("\n=== ISSUED BOOKS ===\n");
    for(int i=0;i<issue_count;i++)
    {
        printf("Member ID: %s | ISBN: %s | Issue Date: %s | Return Date: %s\n",
               issues[i].member_id, issues[i].isbn, issues[i].issue_date, issues[i].return_date);
    }
}

void viewoverdueBooks()
{
    if (issue_count == 0) {
        printf("No issued books found!\n");
        return;
    }
    printf("\n=== OVERDUE BOOKS ===\n");
    for(int i=0;i<issue_count;i++)
    {
        printf("Member ID: %s | Book ISBN: %s | Issue Date: %s | Return Date: %s\n",
               issues[i].member_id, issues[i].isbn, issues[i].issue_date, issues[i].return_date);
    }
}

void viewmostissuedBooks()
{
    if (issue_count == 0) {
        printf("No issued books found!\n");
        return;
    }
    printf("\n=== MOST ISSUED BOOKS ===\n");
    for(int i=0;i<issue_count;i++)
    {
        printf("ISBN: %s\n",issues[i].isbn);
    }
}

void viewactivemembers()
{
    if (member_count == 0) {
        printf("No member data found.\n");
        return;
    }
    printf("\n--- Active Members ---\n");
    for(int i=0;i<member_count;i++)
    {
        printf("Name: %s | ID: %s | Contact: %s\n",
               members[i].name, members[i].member_id, members[i].contact);
    }
}

void changePassword()
{
    char username[20],old_password[20],new_password[20];
    int found=0;
    printf("Enter username:");
    scanf("%s",username);
    printf("Enter old password:");
    scanf("%s",old_password);

    for(int i=0;i<user_count;i++)
    {
        if (strcmp(users[i].username,username)==0 && strcmp(users[i].password,old_password)==0)
        {
            found=1;
            printf("Enter new password:");
            scanf("%s",users[i].password);
            if(strlen(users[i].password) < 1) {
                printf("Error: Password cannot be empty!\n");
                return;
            }
            printf("Password changed successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Invalid username or old password.\n");
    }
}

void updateProfile()
{
    char username[20],new_username[20],new_password[20];
    int found=0;
    printf("Enter current username:");
    scanf("%s",username);

    for(int i=0;i<user_count;i++)
    {
        if (strcmp(users[i].username,username)==0)
        {
            found=1;
            printf("Enter new username:");
            scanf("%s",users[i].username);
            if(strlen(users[i].username) < 1) {
                printf("Error: Username cannot be empty!\n");
                return;
            }
            printf("Enter new password:");
            scanf("%s",users[i].password);
            if(strlen(users[i].password) < 1) {
                printf("Error: Password cannot be empty!\n");
                return;
            }
            printf("Profile updated successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Username not found.\n");
    }
}

void main_menu()
{
    printf("Welcome to the Library Management System!\n");
    printf("==============LIBRARY MANAGEMENT SYSTEM================\n");
    printf("1. Book Management\n");
    printf("2. Member Management\n");
    printf("3. Issue/Return Management\n");
    printf("4. Reports and Statistics\n");
    printf("5. Settings\n");
    printf("6. Exit\n");
}

int main()
{
    int choice;

    printf("LIBRARY MANAGEMENT SYSTEM\n");
    printf("1.Sign in\n");
    printf("2.Login\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    
    if (choice==1) 
    { 
        printf("Enter your username:");
        scanf("%s",users[user_count].username);
        if(strlen(users[user_count].username) < 1) {
            printf("Error: Username cannot be empty!\n");
            return 0;
        }
        printf("Enter your password:");
        scanf("%s",users[user_count].password);
        if(strlen(users[user_count].password) < 1) {
            printf("Error: Password cannot be empty!\n");
            return 0;
        }
        user_count++;
        printf("Sign in successful!\n");
        printf("Please login now.\n");
        choice = 2;
    }
    
    if (choice==2)
    { 
        char username2[20],password2[20];
        int found=0;
        printf("Enter your username:");
        scanf("%s",username2);
        printf("Enter your password:");
        scanf("%s",password2);
        
        for(int i=0;i<user_count;i++)
        {
            if (strcmp(users[i].username,username2)==0 && strcmp(users[i].password,password2)==0)
            {
                found=1;
                break;
            }
        }
        
        if (found)
        { 
            printf("Login successful!\n");
            
            while(1) {
                main_menu();
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        printf("\n--- Book Management Selected ---\n");
                        printf("1. Add Book\n");
                        printf("2. View All Books\n");
                        printf("3. Search Book\n");
                        printf("4. Delete Book\n");
                        printf("5. Return to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1: addBook(); break;
                            case 2: viewBooks(); break;
                            case 3: searchBook(); break;
                            case 4: deleteBook(); break;
                            case 5: break;
                            default: printf("Invalid choice!\n");
                        }
                        break;
                        
                    case 2:
                        printf("\n--- Member Management Selected ---\n");
                        printf("1. Add Member\n");
                        printf("2. View All Members\n");
                        printf("3. Search Member\n");
                        printf("4. Delete Member\n");
                        printf("5. Return to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1: addMember(); break;
                            case 2: viewMembers(); break;
                            case 3: searchMember(); break;
                            case 4: deletemember(); break;
                            case 5: break;
                            default: printf("Invalid choice!\n");
                        }
                        break;
                        
                    case 3:
                        printf("\n--- Issue/Return Management Selected ---\n");
                        printf("1. Issue Book\n");
                        printf("2. Return Book\n");
                        printf("3. View Issued Books\n");
                        printf("4. Return to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1: issueBook(); break;
                            case 2: returnBook(); break;
                            case 3: viewIssuedBooks(); break;
                            case 4: break;
                            default: printf("Invalid choice!\n");
                        }
                        break;
                        
                    case 4:
                        printf("\n--- Reports and Statistics Selected ---\n");
                        printf("1. View Overdue Books\n");
                        printf("2. View Most Issued Books\n");
                        printf("3. View Active Members\n");
                        printf("4. Return to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1: viewoverdueBooks(); break;
                            case 2: viewmostissuedBooks(); break;
                            case 3: viewactivemembers(); break;
                            case 4: break;
                            default: printf("Invalid choice!\n");
                        }
                        break;
                        
                    case 5:
                        printf("\n--- Settings Selected ---\n");
                        printf("1. Change Password\n");
                        printf("2. Update Profile\n");
                        printf("3. Return to Main Menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1: changePassword(); break;
                            case 2: updateProfile(); break;
                            case 3: break;
                            default: printf("Invalid choice!\n");
                        }
                        break;
                        
                    case 6:
                        printf("Exiting the system. Goodbye!\n");
                        return 0;
                        
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        }
        else
        { 
            printf("Invalid username or password.\n");
        }
    }
    else
    { 
        printf("Invalid choice.\n");
    }
    
    return 0;
}