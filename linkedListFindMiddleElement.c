#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createLinkedList(int values)
{

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = values;
    newNode->next = NULL;
    return newNode;
}

void insertValue(int values, node **head)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = values;
    newNode->next = NULL;

    node *current = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(node *head)
{
    if(head == NULL)
    {
        printf("No Element in the list\n");
        return;
    }
    printf("The Linked List is \n");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

node *middleNode(node *head)
{
    if(head == NULL)
    {
        printf("No middle Element in the list\n");
        return NULL;
    }
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    int values;
    node *head = NULL;
    while ((scanf("%d", &values)) != EOF)
    {
        if (head == NULL)
        {
            head = createLinkedList(values);
        }
        else
        {
            insertValue(values, &head);
        }
    }

    printLinkedList(head);
    node *middle = middleNode(head);
    printf("The Middle Element is : %d \n", middle->data);

    return 0;
}
