// double Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} node;

node *createNode(int value)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void insertNode(node **head, node *newNode, node **tail)
{
	if (*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}
	else
	{
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
	}
}

void printforward(node *head)
{
    printf("Print forward\n");
	node *current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void printbackward(node *head, node *tail)
{
    printf("tail value %d \n", tail->data);
	node *current = tail;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->prev;
	}
	printf("\n");
}


int main()
{
	node *head = NULL;
	node *tail = NULL;
	char input[50];
	fgets(input, 50, stdin);
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		int num = atoi(token);

		node *newNode = createNode(num);
		insertNode(&head, newNode, &tail);

		token = strtok(NULL, " ");
	}

	printforward(head);
	printbackward(head,tail);

	return 0;
}
