#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int coef;
    int exp;
    struct Node *next;
} node;

node *createNewNode(int coef, int exp)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node *newNode, node **head)
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

void printnode(node *head)
{
    if (head == NULL)
    {
        printf("The polynomial is empty\n");
        return;
    }
    node *current = head;
    while (current != NULL)
    {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL)
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

node *polyAdd(node **head1, node **head2)
{
    node *curr1 = *head1;
    node *curr2 = *head2;
    node *addpoly = NULL;

    if (curr2 == NULL)
    {
        return curr1;
    }

    else if (curr1 == NULL)
    {
        return curr2;
    }

    int exp, sum;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->exp == curr2->exp)
        {
            exp = curr1->exp;
            sum = curr1->coef + curr2->coef;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->exp > curr2->exp)
        {
            exp = curr1->exp;
            sum = curr1->coef;
            curr1 = curr1->next;
        }
        else
        {
            exp = curr2->exp;
            sum = curr2->coef;
            curr2 = curr2->next;
        }

        node *newNode = createNewNode(sum, exp);
        insertNode(newNode, &addpoly);
    }

    // Add remaining terms from the first polynomial
    while (curr1 != NULL)
    {
        node *newNode = createNewNode(curr1->coef, curr1->exp);
        insertNode(newNode, &addpoly);
        curr1 = curr1->next;
    }

    // Add remaining terms from the second polynomial
    while (curr2 != NULL)
    {
        node *newNode = createNewNode(curr2->coef, curr2->exp);
        insertNode(newNode, &addpoly);
        curr2 = curr2->next;
    }

    return addpoly;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int coef, exp;

    char input1[50];
    printf("Enter the 1st polynomiyal\n");
    fgets(input1, 50, stdin);
    int flag = 0;
    char *token1 = strtok(input1, " ,\n");
    while (token1 != NULL)
    {
        if (flag == 0)

        {
            coef = atoi(token1);
            flag = 1;
        }
        else if (flag == 1)
        {
            exp = atoi(token1);
            flag = 2;
        }

        if (flag == 2)
        {
            node *newNode = createNewNode(coef, exp);
            insertNode(newNode, &head1);
            flag = 0;
        }
        token1 = strtok(NULL, " ,\n");
    }

    char input2[50];
    printf("Enter the 2st polynomiyal\n");
    fgets(input2, 50, stdin);
    int flag2 = 0;
    char *token2 = strtok(input2, " ,\n");
    while (token2 != NULL)
    {
        if (flag2 == 0)

        {
            coef = atoi(token2);
            flag2 = 1;
        }

        else if (flag2 == 1)
        {
            exp = atoi(token2);
            flag2 = 2;
        }

        if (flag2 == 2)
        {
            node *newNode = createNewNode(coef, exp);
            insertNode(newNode, &head2);
            flag2 = 0;
        }
        token2 = strtok(NULL, " ,\n");
    }

    printf("First linked list polinomial\n");
    printnode(head1);

    printf("Second linked list polinomial\n");
    printnode(head2);

    printf("Linked List of Added Polynomial\n");
    node *addedPoly = polyAdd(&head1, &head2);
    printnode(addedPoly);

    return 0;
}
