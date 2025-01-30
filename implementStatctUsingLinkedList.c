#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *creatNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(node **head, node *newNode, node **tail)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return;
    }

    node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    *tail = newNode;
}

void printtail(node **head, node **tail)
{
    if (*tail == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *current = *tail;
    while (current != *head)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("%d ", current->data);
    printf("\n");
}

void printstact(node *head, node *tail)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *current = head;
    while (current != tail)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d ", current->data);
    printf("\n");
}

void popElement(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("The list is empty. Nothing to pop.\n");
        return;
    }

    if (*head == *tail)
    {
        int num = (*tail)->data;
        free(*tail);
        *head = NULL;
        *tail = NULL;
        printf("Popped the element: %d\n", num);
        return;
    }

    node *current = *tail;
    int num = (*tail)->data;
    free(*tail);
    *tail = current->prev;
    printf("Poped the element %d  \n", num);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    char input[50];

    printf("Enter the elements to add in stack\n");
    fgets(input, 50, stdin);

    char *token = strtok(input, " \n");
    while (token != NULL)
    {
        int num = atoi(token);
        node *newNode = creatNode(num);
        insertNode(&head, newNode, &tail);
        token = strtok(NULL, " \n");
    }
    printf("This is tail :  %d\n", tail->data);

    printf("prev the element\n");
    printtail(&head, &tail);

    printf("Pop the element\n");
    popElement(&head, &tail);
    printstact(head, tail);

    return 0;
}
