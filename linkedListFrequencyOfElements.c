#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *creatLinkedList(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertValue(node **head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(node *head)
{
    if (head == NULL)
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

void serachEveryElement(node *head, int key)
{
    int found = 0, count = 0;
    node *current = head;

    while (current)
    {
        if(current->data == key)
        {
            found = 1;
            count++;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("The element occured %d times\n", count);
    }
}

int main()
{
    int values;
    node *head = NULL;

    while (scanf("%d", &values) != EOF)
    {
        if (head == NULL)
        {
            head = creatLinkedList(values);
        }

        else
        {
            insertValue(&head, values);
        }
    }
    printLinkedList(head);
    int key;
    printf("Enter the value u want to search\n");
    scanf("%d", &key);
    serachEveryElement(head, key);

    return 0;
}
