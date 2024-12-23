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

int main()
{
    int choice;
    do
    {
        printf("\n1. Add User\n2. Display Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

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
            printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}


void addUser()
{
    FILE *file = fopen("users.txt", "r+");
    if (file == NULL)
    {
        file = fopen("users.txt", "w");
        if (file == NULL)
        {
            printf("Error opening file.\n");
            return;
        }
    }

    User user, existingUser;
    int isDuplicate = 0;

    do
    {
        printf("Enter ID (positive number): ");
        scanf("%d", &user.id);
        if (user.id <= 0)
            printf("ID must be a positive number. Please try again.\n");
    } while (user.id <= 0);

    while (fread(&existingUser, sizeof(User), 1, file))
    {
        if (existingUser.id == user.id)
        {
            isDuplicate = 1;
            break;
        }
    }

    if (isDuplicate)
    {
        printf("Error: Duplicate ID detected. User with ID %d already exists.\n", user.id);
        fclose(file);
        return;
    }

    printf("Enter Name: ");
    scanf("%s", user.name);

    do
    {
        printf("Enter Age (positive number): ");
        scanf("%d", &user.age);
        if (user.age <= 0)
            printf("Age must be a positive number. Please try again.\n");
    } while (user.age <= 0);

    fseek(file, 0, SEEK_END); 
    fwrite(&user, sizeof(User), 1, file);

    fclose(file);
    printf("User added successfully.\n");
}


void displayUsers()
{
    FILE *file = fopen("users.txt", "r");
    User user;

    if (file == NULL)
    {
        printf("No users to display.\n");
        return;
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }

    fclose(file);
}

void updateUser()
{
    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    User user;
    int id, found = 0;

    printf("Enter ID of the user to update: ");
    scanf("%d", &id);

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", user.name);

            do
            {
                printf("Enter new Age (positive number): ");
                scanf("%d", &user.age);
                if (user.age <= 0)
                    printf("Age must be a positive number. Please try again.\n");
            } while (user.age <= 0);
        }
        fwrite(&user, sizeof(User), 1, temp);
    }

    fclose(file);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
        printf("User updated successfully.\n");
    else
        printf("User not found.\n");
}

void deleteUser()
{
    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    User user;
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id != id)
        {
            fwrite(&user, sizeof(User), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
        printf("User deleted successfully.\n");
    else
        printf("User not found.\n");
}