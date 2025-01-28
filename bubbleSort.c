#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printvalue(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void bubbleSort(node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    node *lastSorted = NULL;
    while (lastSorted != *head)
    {
        node *current = *head;

        while (current->next != lastSorted)
        {
            if (current->data < current->next->data)
            {
                int temp = current->next->data;
                current->next->data = current->data;
                current->data = temp;
            }
            current = current->next;
        }
        lastSorted = current;
    }
}

int main()
{
    node *head = NULL;
    char input[100];
    fgets(input, 100, stdin);
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        int num = atoi(token);
        token = strtok(NULL, " ");

        node *newNode = createNode(num);
        insertNode(&head, newNode);
    }

    printf("Original linked list\n");
    printvalue(head);

    bubbleSort(&head);

    printf("After changing the next Element\n");
    printvalue(head);

    return 0;
}
