#include <stdio.h>
#define MAX 5

int queue1[MAX];
int queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

int isFull(int queueNumber)
{
    if (queueNumber == 1)
    {
        return (rear1 + 1) % MAX == front1;
    }
    else
    {
        return (rear2 + 1) % MAX == front2;
    }
}

int isEmpty(int queueNumber)
{
    if (queueNumber == 1)
    {
        return front1 == -1;
    }
    else
    {
        return front2 == -1;
    }
}

void peek(int queueNumber)
{
    if (isEmpty(queueNumber))
    {
        printf("Queue %d is empty. Cannot peek.\n", queueNumber);
    }
    else
    {
        if (queueNumber == 1)
        {
            printf("Queue 1 Peek: %d\n", queue1[front1]);
        }
        else
        {
            printf("Queue 2 Peek: %d\n", queue2[front2]);
        }
    }
}

void enqueue(int queueNumber, int value)
{
    if (isFull(queueNumber))
    {
        printf("Queue %d is full. Cannot enqueue %d\n", queueNumber, value);
        return;
    }

    if (queueNumber == 1)
    {
        if (front1 == -1)
        {
            front1 = 0;
        }
        rear1 = (rear1 + 1) % MAX;
        queue1[rear1] = value;
        printf("Enqueued %d to Queue 1\n", value);
    }
    else
    {
        if (front2 == -1)
        {
            front2 = 0;
        }
        rear2 = (rear2 + 1) % MAX;
        queue2[rear2] = value;
        printf("Enqueued %d to Queue 2\n", value);
    }
}

int dequeue(int queueNumber)
{
    if (isEmpty(queueNumber))
    {
        printf("Queue %d is empty. Cannot dequeue.\n", queueNumber);
        return -1;
    }

    int dequeuedValue;
    if (queueNumber == 1)
    {
        dequeuedValue = queue1[front1];
        if (front1 == rear1)
        {
            front1 = rear1 = -1;
        }
        else
        {
            front1 = (front1 + 1) % MAX;
        }
        printf("Dequeued %d from Queue 1\n", dequeuedValue);
    }
    else
    {
        dequeuedValue = queue2[front2];
        if (front2 == rear2)
        {
            front2 = rear2 = -1;
        }
        else
        {
            front2 = (front2 + 1) % MAX;
        }
        printf("Dequeued %d from Queue 2\n", dequeuedValue);
    }
    return dequeuedValue;
}

void display()
{
    int queueNumber = 1;
    if (isEmpty(queueNumber))
    {
        printf("Queue %d is empty.\n", queueNumber);
        return;
    }

    printf("Queue %d: ", queueNumber);
    int index;
    index = front1;
    while (index != rear1)
    {
        printf("%d ", queue1[index]);
        index = (index + 1) % MAX;
    }
    printf("%d\n", queue1[rear1]);
}

void push(int ele)
{

    if (isFull(1))
    {
        printf("Queue 1 is full. Cannot enqueue %d\n", ele);
        return;
    }
    if (front1 == -1)
    {
        enqueue(1, ele);
    }

    else
    {

        while (!isEmpty(1))
        {
            int value = dequeue(1);
            enqueue(2, value);
        }
        enqueue(1, ele);
        while (!isEmpty(2))
        {
            int value = dequeue(2);
            enqueue(1, value);
        }
    }
}

void size()
{
    int count = 0;
    for (int itr = front1; itr <= rear1; itr++)
    {
        count++;
    }
    printf("%d\n", count);
}
int main()
{
    printf("Queue operations\nEnter operations\n");
    int opr, queueChoice;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5.size\n");

    while (1)
    {
        printf("\nEnter operation (1-4): ");
        scanf("%d", &opr);
        queueChoice = 1;
        if (opr == 1)
        {

            printf("Enter element to push: ");
            int ele;
            scanf("%d", &ele);
            push(ele);
        }
        else if (opr == 2)
        {

            dequeue(queueChoice);
        }
        else if (opr == 3)
        {

            peek(queueChoice);
        }
        else if (opr == 4)
        {

            display();
        }
        else if (opr == 5)
        {
            size();
        }
        else
        {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
