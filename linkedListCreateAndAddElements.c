#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int values)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = values;
    newNode->next = NULL;
    return newNode;
}

void insertData(int values, struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = values;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;  
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int AdditionOfLinkedList(struct Node *head)
{
    printf("The sum is ");
    int sum = 0;

    struct Node *temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    
    return sum;
}

int main()
{
    int values;
    struct Node *head = NULL;

    while (scanf("%d", &values) != EOF)
    {
        if (head == NULL)
        {
            head = createLinkedList(values); 
        }
        else
        {
            insertData(values, &head);  
        }
    }

    printLinkedList(head); 
    int sum = AdditionOfLinkedList(head);
    printf("%d\n", sum);

    return 0;
}
