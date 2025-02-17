// Create Hash Table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define table_size 10

typedef struct Node
{
    char key;
    int value;
    struct Node *next;
} node;

node *hashTable[table_size];

// -------------------------- Hash function

int hashFuntion(char *key)
{
    int sum = 0;
    for (int index = 0; key[index] != '\0'; index++)
    {
        sum += key[index];
    }

    return sum % table_size;
}
// --------------------------------------
// -------------------------------------- Insert Key-Value Pair

void insertValue(char *key, int value)
{
    int index = hashFuntion(key);
    node *newNode = (node *)malloc(sizeof(node));

    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}
// ---------------------------------------
// --------------------------------------- Search for a key

int searchKey(char *key)
{
    int index = hashFuntion(key);
    node *temp = hashTable[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}
// -----------------------------------------

int main()
{
    int hashingValue = (hashFuntion("DOG"));
    printf("%d", hashingValue);
    return 0;
}