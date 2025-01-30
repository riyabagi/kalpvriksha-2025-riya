#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNewNode(int values)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = values;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node *newNode, node **head)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printnode(node **head)
{
    if (head == NULL)
    {
        printf("The linked list is empty");
        return;
    }
    node *current = *head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteKey(int key, node **head)
{
    if (*head == NULL)
    {
        printf("Key Not found, The Linked list is empty\n");
    }

    node *current = *head;
    if (current->data == key)
    {
        *head = current->next;
        free(current);
        printf("Deleted the value\n");
        return;
    }

    node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == key)
        {
            prev->next = current->next;
            free(current);
            printf("Deleted the value");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found\n");
}

int main()
{
    int values;
    node *head = NULL;
    printf("Enter the values\n");
    while (scanf("%d", &values) != EOF)
    {
        node *newNode = createNewNode(values);
        insertNode(newNode, &head);
    }

    printf("Origional linked list\n");
    printnode(&head);

    printf("Enter a value to delete\n");
    int key;
    scanf("%d", &key);
    deleteKey(key, &head);

    printf("Linked list after deleting the value\n");
    printnode(&head);

    return 0;
}
