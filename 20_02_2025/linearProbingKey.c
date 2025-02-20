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

typedef struct hashmap
{
    int key;
    int value;
} hashmap;

int hashFunction(int vlaue)
{
    return vlaue % MAX;
}

void addValue(hashmap map[], int value)
{
    int index = hashFunction(value);

    if (map[index].value == -1)
    {
        map[index].key = index;
        map[index].value = value;
        return;
    }

    int newIndex = (index + 1) % MAX;
    while (newIndex != index)
    {
        if (map[newIndex].value == -1)
        {
            map[newIndex].key = newIndex;
            map[newIndex].value = value;
            return;
        }

        newIndex = (newIndex + 1) % MAX;
    }

    if (newIndex == index)
    {
        printf("Hash table is full! Cannot insert %d\n", value);
    }
}

void deleteValue(hashmap map[], int value)
{
    int index = hashFunction(value);

    if (map[index].value == value)
    {
        printf("Deleted %d \n", map[index].value);
        map[index].value = -1;
        map[index].key = -1;
        return;
    }

    int newIndex = (index + 1) % MAX;
    while (newIndex != index)
    {
        if (map[newIndex].value == value)
        {
            printf("Deleted %d \n", map[newIndex].value);
            map[newIndex].value = -1;
            map[newIndex].key = -1;
            return;
        }

        newIndex = (newIndex + 1) % MAX;
    }

    printf("Element not found \n");
}

void searchValue(hashmap map[], int value)
{
    int index = hashFunction(value);

    if (map[index].value == value)
    {
        printf("element found\n");
        return;
    }

    int newIndex = (index + 1) % MAX;

    while (newIndex != index)
    {
        if (map[newIndex].value == value)
        {
            printf("element found\n");
            return;
        }
        newIndex = (newIndex + 1) % MAX;
    }

    printf("Element not fount\n");
}

void displayValue(hashmap map[])
{
    printf("Hash map values are\n");
    for (int index = 0; index < MAX; index++)
    {
        if (map[index].value != -1)
        {
            printf("%d %d \n", map[index].key, map[index].value);
        }
    }
    printf("\n");
}

int main()
{
    hashmap map[MAX];
    for (int index = 0; index < MAX; index++)
    {
        map[index].key = -1;
        map[index].value = -1;
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
            addValue(map, value);
            break;

        case Delete:
            printf("Enter the element to Delete\n");
            scanf("%d", &value);
            deleteValue(map, value);
            break;

        case Search:
            printf("Enter the element to search\n");
            scanf("%d", &value);
            searchValue(map, value);
            break;

        case Display:
            displayValue(map);
            break;

        case Exit_Case:
            printf("Exiting...\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}