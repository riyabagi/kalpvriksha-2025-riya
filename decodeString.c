// Q: Decode a String Encoded with Run-Length Encoding
// Given a compressed string like "3[a]2[bc]", expand it to "aaabcbc".
// Example:
// Input: "3[a2[c]]"
// Output: "accaccacc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
char strStack[MAX][MAX];
int top = -1;
int top1 = -1;

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

void pushStrElements(char arr[][MAX], char *values)
{
    if (top1 == MAX - 1)
    {
        printf("The stack is full");
        return;
    }

    strcpy(arr[++top1], values);
}

char *popString(char arr[][MAX])
{
    if (top1 == -1)
    {
        printf("The stack is empty");
        return "";
    }

    return arr[top1--];
}

int main()
{
    char input[20], output[1000];
    int size, values, count = 0;
    char str[MAX] = "", result[MAX * MAX];

    printf("Enter the string\t");
    scanf("%s", input);

    for (int index = 0; index < strlen(input); index++)
    {
        if (isdigit(input[index]))
        {
            int num = input[index] - '0';
            pushElements(stack, num);
        }

        else if (isalpha(input[index]))
        {
            str[count++] = input[index];
        }

        else if (input[index] == '[')
        {
            str[count] = '\0';
            pushStrElements(strStack, str);
            count = 0;
            strcpy(str, "");
        }

        else
        {
            str[count] = '\0';
            int num = popStack(stack);
            char temp[MAX] = "", expanded[MAX] = "";
            strcpy(temp, popString(strStack));

            for (int itr = 0; itr < num; itr++)
            {
                strcat(expanded, str);
            }
            strcat(temp, expanded);

            pushStrElements(strStack, temp);
            strcpy(str, "");
            count = 0;
        }
    }

    printf("Decoded string: %s\n", strStack[top1]);

    return 0;
}
