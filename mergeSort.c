#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head = NULL;

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;

    return newnode;
}

void insertatend(int value)
{
    struct node *newnode = createnode(value);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void displaySLL(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d-", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

struct node *split(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        if (fast != NULL)
        {
            slow = slow->next;
        }
    }
    struct node *second = slow->next;
    slow->next = NULL;
    return second;
}

struct node *merge(struct node *temp, struct node *second)
{

    if (temp == NULL)
        return second;
    if (second == NULL)
        return temp;

    if (temp->value < second->value)
    {
        temp->next = merge(temp->next, second);
        return temp;
    }
    else
    {
        second->next = merge(temp, second->next);
        return second;
    }
}

struct node *mergesortSLL(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct node *second = split(head);

    head = mergesortSLL(head);
    second = mergesortSLL(second);

    return merge(head, second);
}

struct Node *deleteMiddle(struct node *head)
{
    if (!head || !head->next)
    {
        free(head);
        return NULL;
    }

    struct node *slow = head;
    struct node *fast = head;
    struct node *prev = NULL;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev)
    {
        prev->next = slow->next;
    }

    free(slow);
}

int main()
{
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *token;
    token = strtok(input, " ");
    while (token != NULL)
    {
        int num = atoi(token);
        insertatend(num);
        token = strtok(NULL, " ");
    }

    printf("\nBefore sorting\n  :");
    displaySLL(head);

    printf("\nAfter after sorting\n  :");
    head = mergesortSLL(head);
    displaySLL(head);

    deleteMiddle(head);
    printf("\n After deleting\n");
    displaySLL(head);
}
