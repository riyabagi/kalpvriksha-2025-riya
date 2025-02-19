#include <stdio.h>
#include <string.h>
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
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    while (curr != head)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("%d ", curr->data);

    printf("\n");
}

int main()
{
    int values;
    node *head = NULL;

    while (scanf("%d", &values) == 1)
    {

        node *newNode = createNode(values);
        insertNode(&head, newNode);

        if (getchar() == '\n')
        {
            break;
        }
    }

    printList(head);

    return 0;
}