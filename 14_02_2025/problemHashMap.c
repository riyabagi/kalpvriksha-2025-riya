#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct hashMap
{
    char name[50];
    long int phone;
    struct hashMap *next;
} hashMap;

hashMap *hashTable[MAX];

int hashFuntion(char *name)
{
    int sum = 0;
    for (int index = 0; name[index] != '\0'; index++)
    {
        sum += name[index];
    }
    return sum % MAX;
}

hashMap *createNode(char *name, long int phone)
{
    hashMap *newNode = (hashMap *)malloc(sizeof(hashMap));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->phone = phone;
    newNode->next = NULL;
    return newNode;
}

void insertValue(int index, hashMap **hashTable, hashMap *newNode)
{
    if (!hashTable[index])
    {
        hashTable[index] = newNode;
        return;
    }

    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void displayHashmap(hashMap **hashTable)
{
    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index])
        {
            hashMap *temp = hashTable[index];
            while (temp)
            {
                printf("Index %d Name %s, Phone %ld ", index, temp->name, temp->phone);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    int size;
    long int phone;
    char name[50];

    printf("Enter the number of data you want to enter\n");
    scanf("%d", &size);
    getchar();

    printf("Enter name and phone\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%s", name);
        scanf("%ld", &phone);

        hashMap *newNode = createNode(name, phone);
        int index = hashFuntion(name);
        insertValue(index, hashTable, newNode);
    }
    displayHashmap(hashTable);
    return 0;
}