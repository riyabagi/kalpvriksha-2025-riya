#include <stdio.h>
#include <string.h>

#define MAX 10

typedef enum menu
{
    Add = 1,
    Delete,
    Search,
    Display,
    Exit_Case
} menu;

menu get_menu(char choice[])
{
    int result;
    
    if (strcmp(choice, "Add") == 0)
        result = 1;
    if (strcmp(choice, "Delete") == 0)
        result = 2;
    if (strcmp(choice, "Search") == 0)
        result = 3;
    if (strcmp(choice, "Display") == 0)
        result = 4;
    if (strcmp(choice, "Exit_Case") == 0)
        result = 5;
    return result;
}

int hashFunction(int vlaue)
{
    return vlaue % MAX;
}

void addValue(int hashmap[], int value)
{
    int index = hashFunction(value);

    if (hashmap[index] == -1)
    {
        hashmap[index] = value;
        return;
    }

    int newIndex = (index + 1) % MAX;
    while (newIndex != index)
    {
        if (hashmap[newIndex] == -1)
        {
            hashmap[newIndex] = value;
            return;
        }

        newIndex = (newIndex + 1) % MAX;
    }
}

void deleteValue(int hashmap[], int value)
{
    int index = hashFunction(value);

    if (hashmap[index] == value)
    {
        printf("Deleted %d \n", hashmap[index]);
        hashmap[index] = -1;
        return;
    }

    int newIndex = (index + 1) % MAX;
    while (newIndex != index)
    {
        if (hashmap[newIndex] == value)
        {
            printf("Deleted %d \n", hashmap[newIndex]);
            hashmap[newIndex] = -1;
            return;
        }

        newIndex = (newIndex + 1) % MAX;
    }

    printf("Element not found \n");
}

void searchValue(int hashmap[], int value)
{
    int index = hashFunction(value);

    if (hashmap[index] == value)
    {
        printf("element found\n");
        return;
    }

    int newIndex = (index + 1) % MAX;

    while (newIndex != index)
    {
        if (hashmap[newIndex] == value)
        {
            printf("element found\n");
            return;
        }
    }

    printf("Element not fount\n");
}

void displayValue(int hashmap[])
{
    printf("Hash map values are\n");
    for (int index = 0; index < MAX; index++)
    {
        if (hashmap[index] != -1)
        {
            printf("%d ", hashmap[index]);
        }
    }
    printf("\n");
}

int main()
{
    int hashmap[MAX];
    for (int index = 0; index < MAX; index++)
    {
        hashmap[index] = -1;
    }

    char choice[10];
    int value;
    menu s;

    while (s != 5)
    {
        printf("Enter your choice\n");
        scanf("%s", choice);
        s = get_menu(choice);

        switch (s)
        {
        case Add:
            printf("Enter the element to add\n");
            scanf("%d", &value);
            addValue(hashmap, value);
            break;

        case Delete:
            printf("Enter the element to Delete\n");
            scanf("%d", &value);
            deleteValue(hashmap, value);
            break;

        case Search:
            printf("Enter the element to search\n");
            scanf("%d", &value);
            searchValue(hashmap, value);
            break;

        case Display:
            displayValue(hashmap);
            break;

        default:
            break;
        }
    }

    return 0;
}