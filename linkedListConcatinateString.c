// concatinate string Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *value;
	struct Node *next;
} node;

node *createNode(char *value)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->value = strdup(value);
	newNode->next = NULL;
	return newNode;
}

void insertNode(node **head, node *newNode)
{
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	else
	{
		node *current = *head;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void printList(node *head)
{
	node *current = head;
	while (current != NULL)
	{
		printf("%s ", current->value);
		current = current->next;
	}
	printf("\n");
}

int compare(const char *str1, const char *str2)
{
	return(strcmp(str1,str2));
}

void concatinateString(node **head1, node **head2)
{
	if(*head1 == NULL)
	{
		*head1 = *head2;
		*head2 = NULL;
		return;
	}
	if(*head2 == NULL)
	{
		return;
	}

	node *current1 = *head1;
	node *current2 = *head2;
	node *prev = NULL;


	while(current1 != NULL && current2 != NULL)
	{
		if (compare(current1->value, current2->value) <= 0)
		{
			prev = current1;
			current1 = current1->next;
		}
		else
		{
			node *next2 = current2->next;
			if (prev == NULL)
			{
				current2->next = *head1;
				*head1 = current2;
			}
			else
			{
				prev->next = current2;
				current2->next = current1;
			}
			prev = current2;
			current2 = next2;
		}
	}
	if(current2 != NULL)
	{
		prev->next = current2;
	}
}

int main()
{
	node *head1 = NULL;
	node *head2 = NULL;
	char input1[100];
	printf("Enter first string: ");
	fgets(input1, 100, stdin);

	char *token = strtok(input1, " ");
	while (token != NULL) {
		node *newNode = createNode(token);
		insertNode(&head1, newNode);
		token = strtok(NULL, " \n");
	}

	char input2[100];
	printf("Enter second string: ");
	fgets(input2, sizeof(input2), stdin);

	char *token2 = strtok(input2, " \n");
	while (token2 != NULL) {
		node *newNode = createNode(token2);
		insertNode(&head2, newNode);
		token2 = strtok(NULL, " \n");
	}
	concatinateString(&head1, &head2);
	printf("Concatenated list:\n");
	printList(head1);
	return 0;
}
