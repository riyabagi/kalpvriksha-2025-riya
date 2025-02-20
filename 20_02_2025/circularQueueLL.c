#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum op
{
    Push = 1,
    Pop,
    IsEmpty,
    Display,
    Exit_case
} op;

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

void popQueue(node **head)
{
    if (*head == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    node *curr = *head;

    if (curr->next == curr)
    {
        *head = NULL;
        free(curr);
        return;
    }

    *head = (*head)->next;
    (*head)->prev = curr->prev;
    curr->prev->next = head;
    free(curr);
}

void isEmptyFunction(node *head)
{
    if (head == NULL)
    {
        printf("True\n");
        return;
    }

    else
    {
        printf("False\n");
    }
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
    int values, pri, choice = 0;
    node *head = NULL;

    while (choice != 5)
    {
        printf("\n1. Push\n2. Pop\n3. IsEmpty\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case Push:
            printf("Enter the element: ");
            scanf("%d", &values);
            printf("    Enter the priority: ");
            scanf("%d", &pri);
            node *newNode = createNode(values);
            insertNode(&head, newNode);
            break;

        case Pop:
            popQueue(&head);
            break;

        case IsEmpty:
            isEmptyFunction(head);
            break;

        case Display:
            printList(head);
            break;

        case Exit_case:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice, please enter a valid option!\n");
            break;
        }
    }

    return 0;
}