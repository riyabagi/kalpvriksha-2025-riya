// linear search

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

node *createNode(int value)
{
	node *newNode =(node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertNode(node **head, node *newNode)
{
	if(*head == NULL)
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

void printvalue(node **head)
{
	node *current = *head;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

void searchValue(node **head, int val)
{
	if(*head == NULL)
	{
		printf("The linked list is empty");
	}
	node *current = *head;
	node *first = *head;
	while(current != NULL)
	{
		if(current->data == val)
		{
			printf("The value is found\n");
			int temp = current->data;
			current->data = first->data;
			first->data = temp;
			return;
		}
		current = current->next;
	}

	printf("Key is not present in the linked list");
}

int main()
{
	int size;
	printf("Enter the size\n");
	scanf("%d",&size);
	
	if(size <= 0)
	{
	    printf("Enter valid size");
	    return 1;
	}

	int values;
	node *head = NULL;

	printf("Enter the values\n");
	for(int index = 0; index<size; index++)
	{
		scanf("%d", &values);
		node *newNode = createNode(values);
		insertNode(&head, newNode);
	}
	printf("Origional linked list\n");
	printvalue(&head);

	int val;
	printf("Enter the value you want to search\n");
	scanf("%d", &val);
	searchValue(&head, val);

    printf("After swaping with first element\n");
	printvalue(&head);

	return 0;
}
