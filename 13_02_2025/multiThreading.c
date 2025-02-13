// The program demonstrates parallel execution using pthread_create()

#include<stdio.h>
#include<pthread.h>
#include <unistd.h> //For sleep funtion

void *print_message(void *args)
{
    int thread_num = *(int *)args;
    printf("Thread %d: Running\n", thread_num);
    sleep(1);
    printf("Thread %d: Finished\n", thread_num);
    return NULL;
}

int main()
{
    pthread_t threads[100000];
    // int thread_nums[3] = {1, 2, 3};

    for (int index = 0; index < 1000; index++)
    {
        pthread_create(&threads[index], NULL, print_message, &index); // &thread_nums[index]: Pointer to the thread number, passed as an argument to print_message().
    }

    for (int index = 0; index < 1000; index++)
    {
        pthread_join(threads[index], NULL); // Wait for threads to finish
    }

    printf("All threads finished execution.\n");
    return 0;
}