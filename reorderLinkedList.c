#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(node **head, node *newNode, node **tail)
{
    if (*head == NULL)
    {
        *head = *tail = newNode;
        return;
    }

    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}

void printReorderd(node *head, node *tail)
{
    node *curr = head;
    node *curr2 = tail;

    if(curr2 == curr)
    {
        printf("%d ",curr2->data);
        return;
    }

    while (curr != NULL && curr2 != NULL)
    {
        if (curr->next == NULL)
        {
            return;
        }
        printf("%d ", curr->data);

        curr->prev = NULL;
        curr = curr->next;

        if (curr2->prev == NULL)
        {
            return;
        }
        printf("%d ", curr2->data);

        curr2->next = NULL;
        curr2 = curr2->prev;
    }

    printf("\n");
}

// void printNode(node *head)
// {
//     if (head == NULL)
//     {
//         printf("The linked list is empty\n");
//         return;
//     }
//     node *curr = head;
//     while (curr != NULL)
//     {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
//     printf("\n");
// }

int main()
{
    int size;
    int values;
    node *head = NULL;
    node *tail = NULL;

    printf("Enter the size of linkedlist\t");
    scanf("%d", &size);
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode, &tail);
    }

    printReorderd(head, tail);

    return 0;
}
