#include <stdio.h>
// #include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct hashmap
{
    int value;
} hashmap;

hashmap *hashTable[MAX] = {NULL};

int hashfuntion(int value)
{
    return value % 10;
}

void insertValue(int value)
{
    int index = hashfuntion(value);

    for (int count = 0; count < MAX; count++)
    {
        int newIndex = (index + count) % MAX;

        if (hashTable[newIndex] == NULL)
        {
            hashTable[newIndex] = (hashmap *)malloc(sizeof(hashmap));
            hashTable[newIndex]->value = value;
            return;
        }
    }

    printf("No enough space\n");
}

void printTable()
{
    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index] != NULL)
        {
            printf("%d %d \n", index, hashTable[index]->value);
        }
    }
}

void freeTable()
{
    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index] != NULL)
        {
            free(hashTable[index]);
            hashTable[index] = NULL;
        }
    }
}

int main()
{
    int size, value;
    printf("Enter the number of elements\n");
    scanf("%d", &size);

    printf("Enter the elements\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &value);
        insertValue(value);
    }
    printTable();
    freeTable();
}