#include <stdio.h>
#include <stdlib.h>

typedef enum op
{
    Push = 1,
    Pop,
    // Peek,
    IsEmpty,
    Display,
    Exit_case
} op;

typedef struct Node
{
    int data;
    int pri;
    struct Node *next;
} node;

node *createNode(int value, int pri)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->pri = pri;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node **head, node *newNode)
{
    if (*head == NULL || (*head)->pri > newNode->pri)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *curr = *head;
    node *prev = NULL;

    while (curr != NULL && curr->pri <= newNode->pri)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;
}

void popQueue(node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *curr = *head;
    *head = (*head)->next;
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
        printf("False\n");
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

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
            node *newNode = createNode(values, pri);
            insertNode(&head, newNode);
            break;

        case Pop:
            popQueue(&head);
            break;

            // case Peek:
            //     peekFunction(head);
            //     break;

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