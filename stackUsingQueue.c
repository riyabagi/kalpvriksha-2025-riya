#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return 1; 
    }
    return 0;
}

int isEmpty()
{
    if (front == rear)
    {
        return 1; 
    }
    return 0;
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot peek.\n");
    }
    else
    {
        printf("Peek: %d\n", queue[front]);
    }
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("stack is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX; 
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
    if (front == rear)
    {                     
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX; 
    }
    return dequeuedValue;
}

void push(int value)
{
    enqueue(value);
    int temprear = rear;
    while (front != temprear)
    {
        int value = dequeue();
        enqueue(value);
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int index = front;
    while (index != rear)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX; 
    }
    printf("%d\n", queue[rear]); 
}

int main()
{
    printf("Queue operations \nEnter operations\n");
    int opr;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n");

    while (1)
    {
        printf("\nEnter operation (1-4): ");
        scanf("%d", &opr);

        if (opr == 1)
        {
            printf("Enter element to enqueue: ");
            int ele;
            scanf("%d", &ele);
            push(ele);
        }
        else if (opr == 2)
        {
            dequeue();
        }
        else if (opr == 3)
        {
            peek();
        }
        else if (opr == 4)
        {
            display();
        }
        else
        {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
