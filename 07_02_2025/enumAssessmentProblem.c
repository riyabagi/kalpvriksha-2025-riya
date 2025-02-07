#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum timeSpace
{
    O_1,
    O_log_n,
    O_n,
    O_n_log_n,
    O_n2,
    O_n3,
    O_2n,
    O_n_fact
} timeSpace;

typedef struct ComplexityMap
{
    char name[10];
    timeSpace value;
} ComplexityMap;

ComplexityMap complexities[] = {
    {"O(1)", O_1},
    {"O(log n)", O_log_n},
    {"O(n)", O_n},
    {"O(n log n)", O_n_log_n},
    {"O(n²)", O_n2},
    {"O(n³)", O_n3},
    {"O(2^n)", O_2n},
    {"O(n!)", O_n_fact}};

typedef struct Node
{
    timeSpace timeComplexity;
    timeSpace spaceComplexity;
    struct Node *next;
} node;

node *createNode(timeSpace time, timeSpace space)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->timeComplexity = time;
    newNode->spaceComplexity = space;
    newNode->next = NULL;
    return newNode;
}

int compareComplexities(timeSpace t1, timeSpace s1, timeSpace t2, timeSpace s2)
{
    if (t1 < t2)
        return -1;
    if (t1 > t2)
        return 1;
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

void insertSorted(node **head, timeSpace timeComp, timeSpace spaceComp)
{
    node *newNode = createNode(timeComp, spaceComp);
    if (*head == NULL || compareComplexities(timeComp, spaceComp, (*head)->timeComplexity, (*head)->spaceComplexity) < 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *current = *head;
    while (current->next != NULL && compareComplexities(timeComp, spaceComp, current->next->timeComplexity, current->next->spaceComplexity) > 0)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

timeSpace getEnumValue(char *str)
{
    for (int i = 0; i < 8; i++)
    {
        if (strcmp(str, complexities[i].name) == 0)
        {
            return complexities[i].value;
        }
    }
    return -1;
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("Time: %s, Space: %s\n",
               complexities[head->timeComplexity].name,
               complexities[head->spaceComplexity].name);
        head = head->next;
    }
}

int main()
{
    node *head = NULL;

    char input[200];
    printf("Enter time and space complexities (e.g., 'O(n log n) O(1) O(2^n) O(n)'):\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");
    while (token != NULL)
    {
        char *timeComplexityStr = token;
        token = strtok(NULL, " \n");
        if (token == NULL)
            break;
        char *spaceComplexityStr = token;

        timeSpace timeComp = getEnumValue(timeComplexityStr);
        timeSpace spaceComp = getEnumValue(spaceComplexityStr);

        if (timeComp != -1 && spaceComp != -1)
        {
            insertSorted(&head, timeComp, spaceComp);
        }
        else
        {
            printf("Invalid complexity input: %s %s\n", timeComplexityStr, spaceComplexityStr);
        }

        token = strtok(NULL, " \n");
    }

    printf("\nSorted complexities:\n");
    printList(head);

    return 0;
}