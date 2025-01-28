#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
    struct node *prev;
};

struct node *createNode(char value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(struct node **head, char value)
{
    struct node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

struct node *partition(struct node *low, struct node *high)
{
    char pivot = high->value;
    struct node *i = low->prev;
    struct node *j = low;

    while (j != high)
    {
        if (j->value < pivot)
        {
            i = (i == NULL) ? low : i->next;
            char temp = i->value;
            i->value = j->value;
            j->value = temp;
        }
        j = j->next;
    }
    i = (i == NULL) ? low : i->next;
    char temp = i->value;
    i->value = high->value;
    high->value = temp;
    return i;
}

void quickSort(struct node *low, struct node *high)
{
    if (high != NULL && low != high && low != high->next)
    {
        struct node *pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

struct node *findLastNode(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    struct node *head = NULL;

    printf("Enter characters :  ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ' && input[i] != '\n')
        {
            insertAtEnd(&head, input[i]);
        }
    }

    printf("Original List:\n");
    display(head);

    struct node *last = findLastNode(head);
    quickSort(head, last);

    printf("Sorted List:\n");
    display(head);

    return 0;
}
