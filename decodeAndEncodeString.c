#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
    char data[100];
    int index;
} Stack;

char topElement(Stack *stk)
{
    return (stk->data[stk->index]);
}

char popElement(Stack *stk)
{
    char val = stk->data[stk->index];
    stk->index = stk->index - 1;
    return val;
}

void pushElement(Stack *stk, char ch)
{
    stk->index = stk->index + 1;
    stk->data[stk->index] = ch;
}

void displayStack(Stack *stk)
{
    for (int i = 0; i <= stk->index; i++)
    {
        printf("%c", stk->data[i]);
    }
    printf("\n");
}

int main()
{
    char encodedStr[100];
    printf("Enter encoded string: ");
    scanf(" %[^\n]", encodedStr);

    int length = strlen(encodedStr);
    Stack stk;
    stk.index = -1;

    for (int i = 0; i < length; i++)
    {
        if (encodedStr[i] == ']')
        {
            int strSize = 0;
            char *decodedPart = NULL;

            while (topElement(&stk) != '[')
            {
                decodedPart = (char *)realloc(decodedPart, (strSize + 1) * sizeof(char));
                decodedPart[strSize] = popElement(&stk);
                strSize++;
            }
            decodedPart[strSize] = '\0';
            popElement(&stk);

            int repeatCount = popElement(&stk) - '0';

            for (int i = 0; i < repeatCount; i++)
            {
                for (int j = strSize - 1; j >= 0; j--)
                {
                    pushElement(&stk, decodedPart[j]);
                }
            }
        }
        else
        {
            pushElement(&stk, encodedStr[i]);
        }
    }

    displayStack(&stk);

    return 0;
}
