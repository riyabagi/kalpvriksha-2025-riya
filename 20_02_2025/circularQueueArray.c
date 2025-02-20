#include <stdio.h>
#define MAX 5

enum MENU
{
    ENQUEUE = 1,
    DEQUEUE,
    DISPLAY,
    EXIT
};

void enqueue(int queue[], int *front, int *rear, int value)
{
    if (*front == -1)
    {
        queue[++(*front)] = value;
        *rear = *front;
        return;
    }

    if ((*rear + 1) % MAX == *front)
    {
        printf("Queue OverFlow\n");
        return;
    }

    *rear = (*rear + 1) % MAX;
    queue[*rear] = value;
}

void dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue UnderFlow\n");
        return;
    }

    if (*front == *rear)
    {
        printf("Poped %d\n", queue[*front]);
        *front = *rear = -1;
    }

    printf("Poped %d\n", queue[*front]);
    *front = (*front + 1) % MAX;
}

void display(int queue[], int front, int rear)
{

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int index = front;; index = (index + 1) % MAX)
    {
        printf("%d ", queue[index]);
        if (index == rear)
        {
            break;
        }
    }

    printf("\n");
}

int main()
{
    int queue[MAX];
    int choice = 0, front = -1, rear = -1, value;

    while (choice != 4)
    {
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {

        case ENQUEUE:
            printf("Enter value:");
            scanf("%d", &value);
            enqueue(queue, &front, &rear, value);
            break;

        case DEQUEUE:
            dequeue(queue, &front, &rear);
            break;

        case DISPLAY:
            display(queue, front, rear);
            break;

        case EXIT:
            printf("Exit program");
            return 0;
        }
    }
    return 0;
}