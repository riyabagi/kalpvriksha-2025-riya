#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node **head, node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    node *curr = *head;

    if (curr->data > newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // while (curr->next != NULL)
    // {
    //     curr = curr->next;
    // }
    // curr->next = newNode;
}

int main()
{
    int size, values;
    node *head = NULL;

    printf("Enter the size of the array\n");
    scanf("%d", &size);

    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode);
    }
    return 0;
}