#include <stdio.h>
#include <stdlib.h>

enum status
{
    beingProcessed,
    resolved,
    closed,
    reopen,
    deferred,
    d,
    ext
};

typedef struct Node
{
    int data;
    enum status s;
    struct Node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->s = 1;
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
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

void changeStatus(node **head, int id, int choice)
{
    if (*head == NULL)
    {
        printf("Head is null\n");
        return;
    }

    node *curr = *head;
    while (curr != NULL && curr->data != id)
    {
        curr = curr->next;
    }

    curr->s = choice;
}

void display(node **head)
{
    if (*head == NULL)
    {
        printf("head is null");
        return;
    }

    node *curr = *head;
    while (curr != NULL)
    {
        printf("%d %d \n", curr->data, curr->s);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int size, values, id, choice = 0;
    node *head = NULL;

    printf("Enter the size\t");
    scanf("%d", &size);

    printf("Enter the elements\t");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode);
    }

    while (choice != ext)
    {
        printf("Enter the status you want to chage it to\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case beingProcessed:
        case resolved:
        case closed:
        case reopen:
        case deferred:
            printf("Enter the node you want to chage\t");
            scanf("%d", &id);
            changeStatus(&head, id, choice);
            break;
        case d:
            display(&head);
            break;
        case ext:
            printf("Exiting...");
            return 1;
            break;

        default:
            break;
        }
    }

    return 0;
}
