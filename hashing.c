#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node
{
    int key;
    int value;
    struct node *next;
} Node;

typedef struct hashmap
{
    Node *table[MAX];
} HashMap;

void initialize_hashmap(HashMap *hashMap)
{
    for (int index = 0; index < MAX; index++)
    {
        hashMap->table[index] = NULL;
    }
}

Node *create_node(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hash_function(int key)
{
    return key % MAX;
}

void insert(HashMap *hashMap, int key, int value)
{
    int index = hash_function(key);
    Node *newNode = create_node(key, value);
    if (!newNode)
        return;

    newNode->next = hashMap->table[index];
    hashMap->table[index] = newNode;
}

void search(HashMap hashMap, int key)
{
    int index = hash_function(key);
    Node *temp = hashMap.table[index];

    while (temp)
    {
        if (temp->key == key)
        {
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

void delete(HashMap *hashMap, int key)
{
    int index = hash_function(key);
    Node *temp = hashMap->table[index], *prev = NULL;

    while (temp)
    {
        if (temp->key == key)
        {
            if (prev)
            {
                prev->next = temp->next;
            }
            else
            {
                hashMap->table[index] = temp->next;
            }
            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

void display(HashMap hashMap)
{
    printf("Hash Table:\n");
    for (int index = 0; index < MAX; index++)
    {
        if (hashMap.table[index])
        {
            printf("Index %d: ", index);
            Node *temp = hashMap.table[index];
            while (temp)
            {
                printf("(%d, %d)", temp->key, temp->value);
                temp = temp->next;
                if (temp)
                    printf(" -> ");
            }
            printf("\n");
        }
    }
}

enum MENU
{
    INSERT = 1,
    SEARCH,
    DELETE,
    DISPLAY,
    EXIT
};

int main()
{
    HashMap hashMap;
    int key, value, choice = 0;

    initialize_hashmap(&hashMap);

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case INSERT:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(&hashMap, key, value);
            break;
        case SEARCH:
            printf("Enter key: ");
            scanf("%d", &key);
            search(hashMap, key);
            break;
        case DELETE:
            printf("Enter key: ");
            scanf("%d", &key);
            delete (&hashMap, key);
            break;
        case DISPLAY:
            display(hashMap);
            break;
        case EXIT:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
