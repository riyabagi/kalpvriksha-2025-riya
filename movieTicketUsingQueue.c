#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char movieName[MAX];
    int screenType;
    int amount;
    int seatNumber;
    char status[MAX];
    struct Node *next;
    struct Node *prev;
} node;

node *createNode(char movieName[], int screenType, int seatNumber, int amount, char status[])
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory Not allocated\n");
        return NULL;
    }

    strcpy(newNode->movieName, movieName);
    newNode->screenType = screenType;
    newNode->amount = amount;
    newNode->seatNumber = seatNumber;
    strcpy(newNode->status, "Pending");
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertNode(node **head, node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
}

void apporveList(node **head1, node **head2)
{
    if (*head1 == NULL)
    {
        printf("Nothing to approve\n");
        return;
    }

    node *curr = *head1;
    *head1 = (*head1)->next;
    if (*head1 != NULL)
    {
        (*head1)->prev = NULL;
    }

    strcpy(curr->status, "Approved");

    if (*head2 == NULL)
    {
        *head2 = curr;
        curr->next = NULL;
        curr->prev = NULL;
    }
    else
    {
        node *curr2 = *head2;
        while (curr2->next != NULL)
        {
            curr2 = curr2->next;
        }
        curr2->next = curr;
        curr->prev = curr2;
        curr->next = NULL;
    }
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *curr = head;
    while (curr != NULL)
    {
        printf("Movie Name: %s Screen Number: %d Seat Number: %d Amount: %d Status: %s", curr->movieName, curr->screenType, curr->seatNumber, curr->amount, curr->status);
        curr = curr->next;
        printf("\n");
    }
    printf("\n");
}

int main()
{
    node *head1 = NULL, *head2 = NULL;
    int choice = 1;
    while (choice != 5)
    {
        printf("Enter the choice\t");
        scanf("%d", &choice);
        char movieName[MAX], status[] = "pending";
        int screenType, amount, seatNumber;
        switch (choice)
        {
        case 1:
            printf("Movie Name\t");
            getchar();
            scanf("%[^\n]s", movieName);
            printf("Screen\t");
            scanf("%d", &screenType);
            printf("Seat Number\t");
            scanf("%d", &seatNumber);
            printf("Amount\t");
            scanf("%d", &amount);
            node *newNode = createNode(movieName, screenType, seatNumber, amount, status);
            insertNode(&head1, newNode);
            break;

        case 2:
            apporveList(&head1, &head2);
            break;

        case 3:
            display(head1); // booked
            break;

        case 4:
            display(head2); // approved
            break;

        case 5:
            printf("Exiting...");
            return 1;
            break;

        default:
            break;
        }
    }

    return 0;
}
