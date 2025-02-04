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

void printList(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
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

node *merge(node *left, node *right)
{
    if (!left)
    {
        return right;
    }

    if (!right)
    {
        return left;
    }

    node *result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void splitList(node *head, node **front, node **back)
{
    if (head == NULL || head->next == NULL)
    {
        *front = head;
        *back = NULL;
        return;
    }

    node *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(node **head)
{
    if (!(*head) || !(*head)->next)
        return;

    node *left, *right;
    splitList(*head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}

void removeDuplicate(node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    node *curr = *head;
    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    int size, values;
    node *head = NULL;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode);
    }

    printf("Original List:\n");
    printList(head);

    mergeSort(&head);

    printf("Sorted List:\n");
    printList(head);

    printf("After removing the duplicates:\n");
    removeDuplicate(&head);
    printList(head);

    return 0;
}