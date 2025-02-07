/*File System Path Navigation
Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.

Example:
Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
Output: "/usr/bin/"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int top = -1;

char stack[MAX][MAX];

// void pushStack(char arr[MAX][MAX], char *token)
// {
//     if (top == MAX - 1)
//     {
//         printf("Stack overflow\n");
//         return;
//     }

//     strcpy(arr[++top], token);
// }

// void popStack()
// {
//     if (top == -1)
//     {
//         printf("Stack underflow\n");
//         return;
//     }

//     top--;
// }
// int main()
// {
//     char input[500];
//     fgets(input, sizeof(input), stdin);

//     char *token = strtok(input, " [],\"");
//     while (token != NULL)
//     {
//         if (strcmp(token, "cd") == 0)
//         {
//             token = strtok(NULL, " [],\"");

//             if (token == NULL)
//                 break;

//             else if (strcmp(token, "../") == 0)
//             {
//                 popStack();
//             }

//             else
//             {
//                 pushStack(stack, token);
//             }
//         }
//         token = strtok(NULL, " [],\"");
//     }

//     for (int index = 0; index <= top; index++)
//     {
//         printf("%s", stack[index]);
//     }
//     printf("\n");

//     return 0;
// }

void popStack()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    top--;
}

void pushStack(char arr[MAX][MAX], char *token)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    strcpy(arr[++top], token);
}

int main()
{
    char input[500];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \"[]");
    while (token != NULL)
    {
        if (strcmp(token, "cd") == 0)
        {
            token = strtok(NULL, " \"[]");
            if (token == NULL)
            {
                break;
            }

            else if (strcmp(token, "../") == 0)
            {
                popStack();
            }
            else
            {
                pushStack(stack, token);
            }
        }
        token = strtok(NULL, " \"[]");
    }

    for (int index = 0; index <= top; index++)
    {
        printf("%s", stack[index]);
    }
    printf("\n");
    return 0;
}
