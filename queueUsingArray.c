#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}

void peek()
{
    printf("%d\n", queue[front]);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    front++;
    printf("%d", dequeuedValue);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int itr = front; itr <= rear; itr++)
    {
        printf("%d ", queue[itr]);
    }
    printf("\n");
}

int main()
{
    printf("Queue operations \n enter operations\n");
    int choice;
    printf("1.enqueue\n 2.dequeue \n 3. peek \n 4.display\n");

    while (1)
    {

        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("enter elemnet");
            int ele;
            scanf("%d", &ele);
            enqueue(ele);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            display();
        }
        else
        {
            printf("Enter valid operation");
            break;
        }
    }
}
