#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef enum menu
{
    Add = 1,
    Delete,
    Search,
    Display,
    Exit_Case
} menu;

typedef struct Node
{
    int data;
    struct Node *next;
} node;

int hashFunction(int value)
{
    return value % MAX;
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addValue(node *hashmap[], int value)
{
    node *newNode = createNode(value);
    int index = hashFunction(value);
    if (hashmap[index] == NULL)
    {
        hashmap[index] = newNode;
        return;
    }

    node *curr = hashmap[index];
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

void deleteValue(node *hashmap[], int value)
{
    int index = hashFunction(value);

    if (hashmap[index] == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (hashmap[index]->data == value && hashmap[index]->next == NULL)
    {
        printf("Deleted %d", hashmap[index]->data);
        free(hashmap[index]);
        hashmap[index] = NULL;
        return;
    }

    if (hashmap[index]->data == value)
    {
        printf("Deleted %d", hashmap[index]->data);
        node *temp = hashmap[index];
        hashmap[index] = hashmap[index]->next;
        free(temp);
        return;
    }

    node *curr = hashmap[index];
    node *prev = curr;
    while (curr->next != NULL)
    {
        if (curr->data == value)
        {
            printf("Deleted %d\n", curr->data);
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev  = curr;
        curr = curr->next;
    }

    printf("Element not present\n");
}

int main()
{
    node *hashmap[MAX] = {NULL};

    int choice;
    int value;
    menu s;

    while (s != 5)
    {
        printf("Enter your choice\n");
        scanf("%d", choice);

        switch (choice)
        {
        case Add:
            printf("Enter the element to add\n");
            scanf("%d", &value);
            addValue(&hashmap, value);
            break;

        case Delete:
            printf("Enter the element to Delete\n");
            scanf("%d", &value);
            deleteValue(hashmap, value);
            break;

            // case Search:
            //     printf("Enter the element to search\n");
            //     scanf("%d", &value);
            //     searchValue(hashmap, value);
            //     break;

            // case Display:
            //     displayValue(hashmap);
            //     break;

        default:
            break;
        }
    }

    return 0;
}