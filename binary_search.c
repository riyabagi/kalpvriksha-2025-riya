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

void binarySearch(node *head, int val)
{
    if (head == NULL)
    {
        printf("Not found\n");
        return;
    }

    node *start = head;
    node *end = NULL;

    while (start != end)
    {
        node *slow = start;
        node *fast = start;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow->data == val)
        {
            printf("Element found\n");
            slow->next->data = val;
            return;
        }
        else if (slow->data < val)
        {
            start = slow->next;
        }
        else
        {
            end = slow;
        }
    }

    printf("Element not found\n");
}

int main()
{
    int size;
    printf("Enter the size\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Enter valid size\n");
        return 1;
    }

    int values;
    node *head = NULL;

    printf("Enter the values in ascending order\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        node *newNode = createNode(values);
        insertNode(&head, newNode);
    }

    printf("Original linked list\n");
    printvalue(head);

    int val;
    printf("Enter the value you want to search\n");
    scanf("%d", &val);

    binarySearch(head, val);
    
    printf("After changing the next Element");
    printvalue(head);

    return 0;
}
