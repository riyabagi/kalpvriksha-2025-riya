// 2 pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} node;
node *tail = NULL;
node *createNode(int value)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertNode(node **head,node **tail, node *newNode)
{

	if (*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	newNode->prev = *tail;
	*tail = newNode;


}

void printvalue(node *head)
{
	node *current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void twoPointers(node *head, node *tail, int val)
{
	if (head == NULL)
	{
		printf("Not found\n");
		return;
	}

	node *first = head;
	node *last = tail;

	if((first->data + last->data) == val)
	{
		printf("found");
	}
	else if((first->data + last->data) < val)
	{
		twoPointers(first->next,last, val);
	}
	else
		twoPointers(first,last->prev, val);

}

int main()
{
	char input[100];
	fgets(input, 100, stdin);
	char *token;
	token = strtok(input," ");
	node *head = NULL;

	while(token != NULL)
	{
		int num = atoi(token);
		node *newNode = createNode(num);
		insertNode(&head,&tail,newNode);
		token = strtok(NULL," ");
	}

	printf("Original linked list\n");
	printvalue(head);

	int val;
	printf("Enter the sum you want to search\n");
	scanf("%d", &val);

	twoPointers(head,tail, val);

	return 0;
}
