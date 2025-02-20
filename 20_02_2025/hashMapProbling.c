#include <stdio.h>

#define MAX 10

typedef enum menu
{
    Add = 1,
    Delete,
    Search,
    Display,
    Exit_Case
} menu;

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
    for (int i = 0; i < MAX; i++)
    {
        hashmap[i] = -1;
    }

    int choice = 0, value;

    while (choice != 5)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
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