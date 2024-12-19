#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
} User;

void addUser();
void displayUsers();
void updateUser();
void deleteUser();
void readInput(User *user);
void printUser(User user);
int checkUserExists(int id);
void updateOrDeleteUser(int operation); 

int main()
{
    int choice;
    do
    {
        printf("1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void readInput(User *user)
{
    printf("Enter ID: ");
    while (scanf("%d", &user->id) != 1)
    {
        printf("Invalid ID. Please enter a valid integer for ID: ");
        while(getchar() != '\n'); 
    }

    printf("Enter Name: ");
    scanf("%s", user->name);

    printf("Enter Age: ");
    while (scanf("%d", &user->age) != 1)
    {
        printf("Invalid age. Please enter a valid integer for age: ");
        while(getchar() != '\n');
    }
}

void printUser(User user)
{
    printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
}

int checkUserExists(int id)
{
    FILE *file = fopen("users.txt", "r");
    User user;
    int exists = 0;

    if (file == NULL)
    {
        return 0;  
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            exists = 1;  
            break;
        }
    }

    fclose(file);
    return exists;
}

void addUser()
{
    FILE *file = fopen("users.txt", "a");
    User user;

    readInput(&user);

    if (checkUserExists(user.id))
    {
        printf("User with ID %d already exists. Please enter a different ID.\n", user.id);
        fclose(file); 
        return;
    }

    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
    printf("User added successfully.\n");
}

void displayUsers()
{
    FILE *file = fopen("users.txt", "r");
    User user;
    int userFound = 0;

    if (file == NULL)
    {
        printf("No users to display.\n");
        return;
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        printUser(user);
        userFound = 1;
    }

    if (!userFound)
    {
        printf("No users found.\n");
    }

    fclose(file);
}

void updateOrDeleteUser(int operation)
{
    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    User user;
    int id, found = 0;

    if (file == NULL)
    {
        printf("No users found.\n");
        return;
    }

    printf("Enter ID to %s: ", (operation == 1) ? "update" : "delete");
    while (scanf("%d", &id) != 1)
    {
        printf("Invalid ID. Please enter a valid integer for ID: ");
        while(getchar() != '\n'); 
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            found = 1;
            if (operation == 1) 
            {
                printf("Enter new Name: ");
                scanf("%s", user.name);
                printf("Enter new Age: ");
                while (scanf("%d", &user.age) != 1)
                {
                    printf("Invalid age. Please enter a valid integer for age: ");
                    while(getchar() != '\n'); 
                }
            }
        }

        if (operation == 1 || user.id != id) 
        {
            fwrite(&user, sizeof(User), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
    {
        if (operation == 1)
            printf("User updated successfully.\n");
        else
            printf("User deleted successfully.\n");
    }
    else
    {
        printf("User not found.\n");
    }
}

void updateUser()
{
    updateOrDeleteUser(1);  
}

void deleteUser()
{
    updateOrDeleteUser(0);  
}
