#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[100];
int top = -1;

void pushElements(int arr[], int values)
{
    if (top == MAX - 1)
    {
        printf("The stack is full");
        return;
    }

    arr[++top] = values;
}

int popStack(int arr[])
{
    if (top == -1)
    {
        printf("The stack is empty");
        return -1;
    }

    return arr[top--];
}

void sortedInsert(int arr[], int value)
{
    if (top == -1 || arr[top] <= value)
    {
        pushElements(arr, value);
        return;
    }

    int temp = popStack(arr);
    sortedInsert(arr, value);
    pushElements(arr, temp);
}

void sortStack()
{
    if (top == -1)
        return;

    int temp = popStack(stack);
    sortStack();
    sortedInsert(stack, temp);
}

void printStack()
{
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int arr[100];
    int size, values;
    printf("Enter the size\t");
    scanf("%d", &size);
    printf("Enter the elements\t");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        pushElements(stack, values);
    }
    sortStack();
    printf("Elements after sorting\t");
    printStack();
}
