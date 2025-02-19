#include <stdio.h>
#include <stdlib.h>

typedef enum op
{
    Push = 1,
    Pop,
    Peek,
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

void popLinkedList(node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *curr = *head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    printf("Popped %d\n", curr->data);

    if (curr->prev == NULL)
    {
        *head = NULL; 
    }
    else
    {
        curr->prev->next = NULL;
    }

    free(curr); 
}

void peekFunction(node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    printf("Top element: %d\n", curr->data);
}

void isEmptyFunction(node *head)
{
    if (head == NULL)
    {
        printf("True\n");
        return;
    }

    else
        printf("False\n");
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *curr = head;
    printf("Stack: ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    int values, choice;
    node *head = NULL;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case Push:
            printf("Enter the element: ");
            scanf("%d", &values);
            node *newNode = createNode(values);
            insertNode(&head, newNode);
            break;

        case Pop:
            popLinkedList(&head);
            break;

        case Peek:
            peekFunction(head);
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
