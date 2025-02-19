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
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertNode(node **head, node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    node *tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *curr = head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);

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

    printf("Forward: ");
    printList(head);

    return 0;
}