// selection short
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employe
{
	int id;
	char name[50];
	struct Employe *next;
} node;

node *createNode(int ids, char names[50])
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->id = ids;
	strncpy(newNode->name, names, sizeof(newNode->name) -1);
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
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void printvalue(node *head)
{
	node *current = head;
	while (current != NULL)
	{
		printf("%d %s\n", current->id, current->name);
		current = current->next;
	}
	printf("\n");
}

void selectionSort(node **head)
{
    printf("After sorting\n");
	if (*head == NULL)
	{
		printf("Not found\n");
		return;
	}

	int tempid;
	char tempname[50];
	node *current = *head;

	while(current != NULL)
	{
		node *current2 = current->next;

		while(current2 != NULL)
		{
			if(current->id > current2->id)
			{
				tempid = current->id;
				current->id = current2->id;
				current2->id = tempid;

				strncpy(tempname, current->name, sizeof(tempname -1));
				tempname[sizeof(tempname) -1] = '\0';
				strncpy(current->name, current2->name, sizeof(current2->name) - 1);
				current->name[sizeof(current->name) - 1] = '\0';
				strncpy(current2->name, tempname, sizeof(current->name) - 1);
				current2->name[sizeof(current2->name) - 1] = '\0';
			}
			current2 = current2->next;
		}
		current = current->next;
	}
}

int main()
{
	int ids;
	char names[50];
	node *head = NULL;
	char input[100];

	printf("Enter employee data (id,name) or type 'exit' to stop: \n");
	while (1)
	{
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		if (sscanf(input, "%d,%49s", &ids, names) == 2)
		{
			node *newNode = createNode(ids, names);
			insertNode(&head, newNode);
		}
		else
		{
			printf("Invalid input format. Please enter <id>,<name>\n");
		}
	}

	printf("Original linked list\n");
	printvalue(head);

	selectionSort(&head);
	printvalue(head);

	return 0;
}
