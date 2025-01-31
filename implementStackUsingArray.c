#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void pushValue(int arr[], int value)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top] = value;
    printf("Pushed %d\n", value);
}

void popstack(int arr[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Poped element %d \n", arr[top--]);
}

void peek(int arr[])
{
    printf("%d\n", arr[top]);
    return;
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

int main()
{
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. isEmpty\n");
    printf("5. isFull\n");
    printf("6. size\n");
    printf("7. exit\n");

    int choice = 1;
    int arr[100];

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
            pushValue(stack, value);
            break;
        case 2:
            popstack(stack);
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
            res2 = isFull(stack);
            if (res2)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 6:
            printf("%d", top+1);
        case 7:
            return 1;
        }
    }

    return 0;
}
