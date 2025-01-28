#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = NULL;
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
    newnode->prev = temp;
}

void displaySLL(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

struct node *assign(struct node *a, struct node *b)
{
    int temp = a->value;

    b->value = temp;
}

void insertionsortSLL(struct node **head)
{
    struct node *temp = (*head)->next;
    while (temp != NULL)
    {
        struct node *i = temp;
        struct node *j = temp->prev;

        while (j != NULL && i->value < j->value)
        {
            int t = j->value;
            j->value = i->value;
            i->value = t;
            i = j;
            j = j->prev;
        }

        temp = temp->next;
    }
}

struct node *removenode(struct node *head, int k)
{
    if (head == NULL)
        return head;

    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->value == k)
        {
            struct node *del = temp;
            if (prev != NULL)
            {
                prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            temp = temp->next;
            free(del);
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
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

    int k;
    printf("\nEnter a number you want to remove\n");
    scanf("%d", &k);

    insertionsortSLL(&head);
    printf("Normaly sorted\n");
    displaySLL(head);
    printf("After deleting\n");
    head = removenode(head, k);
    displaySLL(head);
}
