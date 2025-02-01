#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void pushValue(char arr[], char value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full");
        return;
    }
    arr[++top] = value;
}

char popStack(char arr[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return (arr[top--]);
}

int main()
{
    char arr[100];
    char input[100];
    char postfix[100];
    int count = 0;
    scanf("%s", input);
    for (int index = 0; index < strlen(input); index++)
    {
        if (isalpha(input[index]))
        {
            postfix[count++] = input[index];
        }
        else if (input[index] == '(')
        {
            pushValue(stack, input[index]);
        }

        else if (input[index] == ')')
        {
            while (stack[top] != '(')

            {
                postfix[count++] = popStack(stack);
            }
            popStack(stack);
        }

        else if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/' || input[index] == '^')
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(input[index]) && stack[top] != '(')
            {
                postfix[count++] = popStack(stack);
            }
            pushValue(stack, input[index]);
        }
    }

    while (top >= 0)
    {
        postfix[count++] = popStack(stack);
    }
    postfix[count] = '\0';

    printf("%s", postfix);

    return 0;
}
