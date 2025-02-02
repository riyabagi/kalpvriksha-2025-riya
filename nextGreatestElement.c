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

void printOutput(int output[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", output[i]);
    printf("\n");
}

int main()
{
    int input[100], output[100];
    int size, values;

    printf("Enter the size\t");
    scanf("%d", &size);

    printf("Enter the elements\t");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &values);
        input[index] = values;
    }

    for (int index = size - 1; index >= 0; index--)
    {
        while (top != -1 && input[index] > stack[top])
        {
            popStack(stack);
        }
        if (top == -1)
        {
            output[index] = -1;
        }

        else
        {
            output[index] = stack[top];
        }

        pushElements(stack, input[index]);
    }

    printf("Next Greatest Elements are: \t");
    printOutput(output, size);
}
