#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
    int top;
    int arr[MAX];
} stack;

void push(stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Queue OverFlow\n");
        return;
    }

    s->arr[++(s->top)] = value;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void popQueue(stack *s)
{
    if (s->top == -1)
    {
        printf("Queue UnderFlow\n");
        return;
    }

    stack s2;
    s2.top = -1;

    while (s->top > 0)
    {
        push(&s2, pop(s));
    }

    int popedElement = pop(s);
    printf("Poped: %d\n", popedElement);

    while (s2.top != -1)
    {
        push(s, pop(&s2));
    }
}

void displayFunc(stack s)
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int index = 0; index <= s.top; index++)
    {
        printf("%d ", s.arr[index]);
    }
    printf("\n");
}

int main()
{
    stack s1;
    s1.top = -1;
    int choice = 0, value;

    while (choice != 4)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &value);
            push(&s1, value);
            break;

        case 2:
            popQueue(&s1);
            break;

        case 3:
            displayFunc(s1);
            break;

        case 4:
            printf("Exiting..\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}