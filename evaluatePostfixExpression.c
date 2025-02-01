#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int top = -1;

void pushNumber(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = value;
}

int popNumber()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char string[100];
    scanf("%s", string);

    for (int index = 0; index < strlen(string); index++)
    {
        if (isdigit(string[index]))
        {
            int num = string[index] - '0';
            pushNumber(num);
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid Expression\n");
                return 1;
            }

            int num1 = popNumber();
            int num2 = popNumber();

            switch (string[index])
            {
            case '+':
                pushNumber(num2 + num1);
                break;
            case '-':
                pushNumber(num2 - num1);
                break;
            case '*':
                pushNumber(num2 * num1);
                break;
            case '/':
                if (num1 == 0)
                {
                    printf("Division by Zero Error\n");
                    return 1;
                }
                pushNumber(num2 / num1);
                break;
            default:
                printf("Invalid Operator: %c\n", string[index]);
                return 1;
            }
        }
    }

    if (top != 0)
    {
        printf("Invalid Expression\n");
        return 1;
    }

    printf("%d\n", popNumber());
    return 0;
}
