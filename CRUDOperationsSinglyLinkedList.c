#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; 

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int position, int value)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = createNode(value);
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int index = 1; index < position - 1 && temp != NULL; index++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head;
    for (int index = 1; index < position && temp != NULL; index++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp->data = newValue;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position)
{
    if (position < 1 || head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *temp = head;
    for (int index = 1; index < position - 1 && temp != NULL; index++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

int main()
{
    int number;
    scanf("%d", &number);

    for (int index = 0; index < number; index++)
    {
        int operation;
        scanf("%d", &operation);

        if (operation == 1)
        {
            int value;
            scanf("%d", &value);
            insertAtEnd(value);
        }
        else if (operation == 2)
        {
            int value;
            scanf("%d", &value);
            insertAtBeginning(value);
        }
        else if (operation == 3)
        {
            int pos, value;
            scanf("%d %d", &pos, &value);
            insertAtPosition(pos, value);
        }
        else if (operation == 4)
        {
            display();
        }
        else if (operation == 5)
        {
            int pos, value;
            scanf("%d %d", &pos, &value);
            updateAtPosition(pos, value);
        }
        else if (operation == 6)
        {
            deleteAtBeginning();
        }
        else if (operation == 7)
        {
            deleteAtEnd();
        }
        else if (operation == 8)
        {
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos);
        }
    }

    return 0;
}
