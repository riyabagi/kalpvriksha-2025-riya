#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hashMap
{
    int index;
    long int data;
    struct hashMap *next;
} hashMap;

#define MAX 10000

hashMap *hashTable[MAX] = {NULL};

int hashFuntion(long int key)
{
    return key % MAX;
}

void insertHash(int count, long int value)
{
    int index = hashFuntion(value);

    hashMap *newNode = (hashMap *)malloc(sizeof(hashMap));
    newNode->index = count;
    newNode->data = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int main()
{
    int count = -1;
    printf("Give the input\n");
    long int value, target;
    char ch;

    while (getchar() != '[')
        ;

    while (scanf("%ld", &value))
    {
        count++;
        insertHash(count, value);

        ch = getchar();
        if (ch == ']')
            break;
    }

    printf("Enter the target\n");
    scanf("%ld", &target);

    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index] != NULL)
        {
            long int required = target - hashTable[index]->data;
            int requiredIndex = hashFuntion(required);

            hashMap *temp = hashTable[requiredIndex];
            while (temp != NULL)
            {
                if (temp->data == required && temp->index != hashTable[index]->index)
                {
                    printf("%d %d\n", temp->index, hashTable[index]->index);
                    return 0;
                }
                temp = temp->next;
            }
        }
    }

    printf("No such pair found\n");
    return 0;
}
