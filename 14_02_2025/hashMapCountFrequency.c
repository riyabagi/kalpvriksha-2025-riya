#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 128
typedef struct hashMapChaning
{
    char key;
    int count;
} hashmap;

hashmap hashTable[MAX] = {0};

int hashFuntion(char key)
{
    // (int)key;
    return key;
}

void countFrequency(char val)
{
    int key = hashFuntion(val);
    if (hashTable[key].count == 0)
        hashTable[key].key = val;

    hashTable[key].count += 1;
}

void printFrequency()
{
    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index].count > 0)
        {
            printf("%c %d\n", hashTable[index].key, hashTable[index].count);
        }
    }
}

int main()
{
    char val[MAX];
    scanf("%s", val);
    for (int index = 0; index < strlen(val); index++)
    {
        countFrequency(val[index]);
    }

    printFrequency();
    return 0;
}