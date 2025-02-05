// 1) Implement an undo-redo feature for a text editor.
// Use two stacks: one for storing undo operations and another for redo operations.
// Implement functions for type(char c) (to add a character), undo(), and redo().
// Example:
// Type: abc → Undo: ab → Undo: a → Redo: ab

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char redostack[MAX];
int top = -1;
int top2 = -1;

void pushStack(char arr[], char value, int *top)
{
    if (*top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    arr[++(*top)] = value;
}

char popStack(char arr[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return arr[(*top)--];
}

void printSack(char arr[], int size)
{
    if (top == -1)
    {
        printf("Empty String\n");
        return;
    }

    for (int index = 0; index <= size; index++)
    {
        printf("%c", arr[index]);
    }
    printf("\n");
}

int main()
{
    char input[MAX];
    printf("Enter the input\n");
    scanf("%s", input);
    getchar();

    for (int index = 0; index < strlen(input); index++)
    {
        pushStack(stack, input[index], &top);
    }

    char choice;
    printf("z for undo\ny for redo\nx for exiting\n");

    while (choice != 'x')
    {
        printf("Enter your choice\n");
        scanf("%c", &choice);
        getchar();

        char undoChar, redoChar;

        switch (choice)
        {
        case 'z':
            undoChar = popStack(stack, &top);
            pushStack(redostack, undoChar, &top2);
            printSack(stack, top);
            break;

        case 'y':
            redoChar = popStack(redostack, &top2);
            pushStack(stack, redoChar, &top);
            printSack(stack, top);
            break;

        case 'x':
            printf("Exiting...\n");
            break;

        default:
            break;
        }
    }

    return 0;
}
