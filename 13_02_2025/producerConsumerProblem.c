#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t condition;

int itr = 0;
int front = 0;
int buffer[10];

void *producer(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        while (itr == 10)
        {
            printf("Buffer is full\n");
            pthread_cond_wait(&condition, &mutex);
        }

        int num = rand() % 100;
        buffer[itr++] = num;
        printf("Produced: %d\n", num);

        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg)
{
    sleep(5);
    while (1)
    {
        pthread_mutex_lock(&mutex);

        while (front > itr )
        {
            printf("Buffer is empty.\n");
            pthread_cond_wait(&condition, &mutex);
            return NULL;
        }
        
        int num = buffer[front++];
        printf("Consumed: %d\n", num);

        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

int main()
{
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
    return 0;
}