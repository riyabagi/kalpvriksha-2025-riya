// 11. Add Two Linked Lists Without Reversing
// Problem: Add two numbers represented by linked lists where each node contains one digit.
// Digits are in forward order (most significant digit first).
// Example: Input: 6→1→7 (617), 2→9→5 (295)
// Output: 9→1→2 (912)

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
    newNode->prev = curr;
    curr->next = newNode;
}

void printNodes(node *head)
{
    if (head == NULL)
    {
        printf("No Elements\n");
        return;
    }

    node *curr = head;
    while (curr->next != NULL)
    {
        // printf("%d ", curr->data);
        curr = curr->next;
    }
    // printf("%d ", curr->data);

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }

    printf("\n");
}

int extractNumber(node *head)
{
    if (head == NULL)
    {
        printf("node is empty\n");
        return 0;
    }

    int sum = 0;
    node *cur = head;
    while (cur != NULL)
    {
        sum = sum * 10 + cur->data;
        cur = cur->next;
    }
    return sum;
}

node *extractAndprintNode(int sum)
{
    node *resultHead = NULL;
    int num = 0, num1 = 0;
    while (sum != 0)
    {
        num = sum % 10;
        node *newNode = createNode(num);
        insertNode(&resultHead, newNode);
        sum = sum / 10;
    }

    return resultHead;
}

int main()
{
    int size, size2, values2, values;
    node *head = NULL;
    node *head2 = NULL;
    printf("Enter the size of 1st linked list\n");
    scanf("%d", &size);

    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode);
    }

    printNodes(head);

    printf("Enter the size of 2nd linked list\n");
    scanf("%d", &size2);

    for (int index = 0; index < size2; index++)
    {
        scanf("%d", &values2);
        node *newNode2 = createNode(values2);
        insertNode(&head2, newNode2);
    }

    printNodes(head2);

    int num1 = extractNumber(head);
    int num2 = extractNumber(head2);

    int sum = num1 + num2;

    node *result = extractAndprintNode(sum);
    printNodes(result);

    return 0;
}
