// 3. Task Manager Command System
// You are designing a task manager system that allows users to add tasks, mark tasks as completed,
// and list pending tasks.
// • "ADD <task>" → Adds a new task (a string of at most 100 characters).
// • "COMPLETE <task>" → Marks the given task as completed. If the task does not exist, ignore
// the command.
// • "PENDING" → Lists all pending tasks in the order they were added.
// Input:
// The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands.
// The next n lines contain a command of one of the following types:
// • "ADD <task>"
// • "COMPLETE <task>"
// • "PENDING"
// Output:
// If there are pending tasks, print each one on a new line. If no pending tasks exist, print "All tasks
// completed".

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef enum
{
    Add = 1,
    Complete,
    Pending,
    Exit
} operations;

typedef struct
{
    char task[MAX];
    char status[10];
} task;

typedef struct
{
    int top;
    task tasks[MAX];
} stack;

void pushTask(stack *s, char task[], char status[])
{
    if (s->top == MAX - 1)
    {
        printf("Stack OverFlow\n");
        return;
    }

    s->top++;
    strcpy(s->tasks[s->top].task, task);
    strcpy(s->tasks[s->top].status, status);
}

void markAsComplete(stack *s, char completeTask[])
{
    for (int index = 0; index < s->top; index++)
    {
        if (strcmp(s->tasks[index].task, completeTask) == 0 && strcmp(s->tasks[index].status, "Pending") == 0)
        {
            strcpy(s->tasks[index].status, "Completed");
        }
    }
}

void displayPending(stack s)
{
    if (s.top == -1)
    {
        printf("No Tasks\n");
        return;
    }

    for (int index = 0; index <= s.top; index++)
    {
        if (strcmp(s.tasks[index].status, "Pending") == 0)
        {
            printf("Task: %s Status: %s", s.tasks[index].task, s.tasks[index].status);
            printf("\n");
        }
    }
}

int main()
{
    int choice = 0;
    char task[MAX], completeTask[MAX];

    stack s;
    s.top = -1;

    printf("1] Add task \n2] Mark as complelted\n3] Display pending task\n4] Exit\n");

    while (choice != 4)
    {
        printf("Enter Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case Add:
            printf("Enter the task\n");
            scanf("%s", task);
            pushTask(&s, task, "Pending");
            break;

        case Complete:
            printf("Enter the task you want to complete\n");
            scanf("%s", completeTask);
            markAsComplete(&s, completeTask);
            break;

        case Pending:
            displayPending(s);
            break;

        case Exit:
            printf("Exiting...\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}