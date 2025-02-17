#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct hashMapChaning
{
    char name[20];
    int marks;
    struct hashMapChaning *next;
} hashmap;

hashmap *hashTable[MAX] = {NULL};

hashmap *createNode(char name[], int marks)
{
    hashmap *newNode = (hashmap *)malloc(sizeof(hashmap));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

int hashFuntion(char name[])
{

    int index = 0;
    for (int itr = 0; name[itr] != '\0'; itr++)
    {
        index += (int)name[itr];
    }
    return index % MAX;
}

void insertHashmap(char name[], int marks)
{
    int index = hashFuntion(name);
    if (hashTable[index]->name == NULL)
    {
        hashTable[index] = createNode(name, marks);
        return;
    }

    hashmap *curr = hashTable[index];
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = createNode(name, marks);
}

void printHashMap()
{
    for (int index = 0; index < MAX; index++)
    {
        if (hashTable[index]->name != '\0')
        {
            hashmap *curr = hashTable[index];
            while (curr != NULL)
            {
                printf("%s %d ", hashTable[index]->name, hashTable[index]->marks);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    char name[20];
    int marks, size;

    printf("Enter number of student\n");
    scanf("%d", &size);

    printf("Enter name and marks\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%s %d", name, &marks);
        insertHashmap(name, marks);
    }

    printHashMap();

    return 0;
}
