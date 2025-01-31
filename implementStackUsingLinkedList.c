#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

int top = -1;
node *tail = NULL;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushValue(node **stack, node *newNode)
{
    if (*stack == NULL)
    {
        *stack = newNode;
        top++;
        return;
    }

    node *curr = *stack;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    tail = newNode;
    top++;
}

void popstack(node **stack, node **tail)
{
    if (*stack == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    if (*tail == *stack)
    {
        free(*stack);
        *stack = NULL;
        *tail = NULL;
        tail--;
        return;
    }

    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    top--;
}

void peek(node *stack)
{
    if (stack == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("%d\n", tail->data);
}

void printStack(node *stack)
{
    node *curr = stack;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int isEmpty(node *stack)
{
    return top == -1;
}

int main()
{
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. isEmpty\n");
    printf("5. print\n");
    printf("6. size\n");
    printf("7. exit\n");

    int choice = 1;
    node *stack = NULL;

    while (choice != 7)
    {
        printf("Enter the choice\t");
        scanf("%d", &choice);
        int value, res, res2;
        switch (choice)
        {
        case 1:
            printf("Enter the value to push\n");
            scanf("%d", &value);
            node *newNode = createNode(value);
            pushValue(&stack, newNode);
            break;
        case 2:
            popstack(&stack, &tail);
            break;
        case 3:
            peek(stack);
            break;
        case 4:
            res = isEmpty(stack);
            if (res)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5:
            printStack(stack);
            break;
        case 6:
            printf("%d", top+1);
        case 7:
            return 1;
        }
    }

    return 0;
}
