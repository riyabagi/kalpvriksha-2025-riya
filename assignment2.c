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

void addUser()
{
    FILE *file = fopen("users.txt", "a");
    User user;

    printf("Enter ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);

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
    User user;
    int id, found = 0;

    if (file == NULL)
    {
        printf("No users found.\n");
        return;
    }

    printf("Enter ID of the user to update: ");
    scanf("%d", &id);

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            found = 1 ;
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
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
