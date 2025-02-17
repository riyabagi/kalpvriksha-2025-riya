// 1. Bookmarked Pages Management System
// You are designing a bookmarking system for an e-book reader that allows users to add bookmarks
// to specific pages, delete the last added bookmark, and list all current bookmarks. The system
// should support the following operations:
// • "BOOKMARK <page>" → Adds a bookmark on the given page (1 ≤ page ≤ 1000).
// • "DELETE" → Removes the most recently added bookmark, if available.
// • "LIST" → Lists all current bookmarks in ascending order.
// Input:
// The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands.
// The next n lines contain a command of one of the following types:
// • "BOOKMARK <page>"
// • "DELETE"
// • "LIST"
// Output:
// If there are any bookmarks, print them in ascending order separated by spaces. If no bookmarks
// exist, print "No bookmarks

#include <stdio.h>

#define MAX 100

typedef enum
{
    Add = 1,
    Delete,
    Display
} op;

typedef struct stack
{
    int top;
    int page[MAX];
} stack;

void addBookMark(stack *s, int pageNumber)
{
    if (s->top == MAX - 1)
    {
        printf("Stack OverFlow\n");
        return;
    }

    s->top++;
    s->page[s->top] = pageNumber;
}

void deletBookMark(stack *s)
{
    if (s->top == -1)
    {
        printf("No bookmark to remove\n");
        return;
    }

    int deletedPage = s->page[s->top--];
    printf("Deleted bookmark is: %d\n", deletedPage);
}

void sortPage(stack *s)
{
    if (s->top == -1)
    {
        return;
    }

    int min, index = 0;
    for (int index1 = 0; index1 <= s->top; index1++)
    {
        min = s->page[index1];
        for (int index2 = index1 + 1; index2 <= s->top; index2++)
        {
            if (min > s->page[index2])
            {
                min = s->page[index2];
                index = index2;
            }
        }

        if (index1 != index)
        {
            int temp = s->page[index1];
            s->page[index1] = min;
            s->page[index] = temp;
        }
    }
}

void displayBookMarks(stack s)
{
    if (s.top == -1)
    {
        printf("No book marks yet\n");
        return;
    }

    for (int index = 0; index <= s.top; index++)
    {
        printf("%d ", s.page[index]);
    }
    printf("\n");
}

int main()
{
    int numOp, choice, pageNumber;
    stack s;
    s.top = -1;
    printf("Enter the number of operations you want to do\n");
    scanf("%d", &numOp);

    printf("1]Add \n2]Delete\n3]Display\n");

    for (int index = 0; index < numOp; index++)
    {
        printf("Choose the operation\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case Add:
            printf("Enter the page you want to book mark\n");
            scanf("%d", &pageNumber);
            addBookMark(&s, pageNumber);
            break;

        case Delete:
            deletBookMark(&s);
            break;

        case Display:
            sortPage(&s);
            displayBookMarks(s);
            break;

        default:
            break;
        }
    }
    return 0;
}