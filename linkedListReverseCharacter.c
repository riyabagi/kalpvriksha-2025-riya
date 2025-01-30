#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next;
} node;

node *createNode(char value)
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
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

node *reverse(node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return NULL;
    }

    node *current = *head;
    node *prev = NULL;
    node *Next = NULL;

    while (current != NULL)
    {
        Next = current->next;
        current->next = prev;
        prev = current;      
        current = Next;
    }

    *head = prev;
    return *head;
}

int main()
{
    node *head = NULL;
    char input[100];
    fgets(input, 100, stdin);
    char *token = input;
    while (*token != '\0' && *token != '\n')
    {
        if (*token != ' ')
        {
            char character = *token;
            node *newNode = createNode(character);
            insertNode(&head, newNode);
        }
        token++;
    }

    printf("Original linked list\n");
    printvalue(head);

    node *Next = reverse(&head);

    printf("After changing the next Element\n");
    printvalue(Next);

    return 0;
}
