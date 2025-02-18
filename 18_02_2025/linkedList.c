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
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

void sortLinkedList(node **head, node *head1, node *head2)
{
    if (head1 == NULL)
    {
        *head = head2;
        return;
    }

    if (head2 == NULL)
    {
        *head = head1;
        return;
    }

    node *curr1 = head1;
    node *curr2 = head2;

    if (curr1->data <= curr2->data)
    {
        *head = curr1;
        curr1 = curr1->next;
    }
    else
    {
        *head = curr2;
        curr2 = curr2->next;
    }

    node *curr = *head;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            curr->next = curr1;
            curr = curr1;
            curr1 = curr1->next;
        }

        else
        {
            curr->next = curr2;
            curr = curr2;
            curr2 = curr2->next;
        }
    }

    if (curr1 != NULL)
    {
        curr->next = curr1;
    }

    else
    {
        curr->next = curr2;
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

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    node *head1 = NULL, *head2 = NULL, *head = NULL;
    int size1, size2, value1, value2;

    printf("Enter the size of the 1st Linked List\n");
    scanf("%d", &size1);

    for (int index = 0; index < size1; index++)
    {
        scanf("%d", &value1);
        node *newNode = createNode(value1);
        insertNode(&head1, newNode);
    }

    printf("Enter the size of the 2nd Linked List\n");
    scanf("%d", &size2);

    for (int index = 0; index < size2; index++)
    {
        scanf("%d", &value2);
        node *newNode = createNode(value2);
        insertNode(&head2, newNode);
    }

    sortLinkedList(&head, head1, head2);
    printList(head);

    return 0;
}