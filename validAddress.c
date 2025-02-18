// A valid IPv4 address consists of four decimal numbers (0-255) separated by dots (.).
// A valid IPv6 address consists of eight groups of hexadecimal numbers (0-FFFF) separated by colons (:).
// If the given string does not match either format, return "Neither".

// Input
// A single string representing the IP address.

// Output
// Return one of the following:
// "IPv4" if the input is a valid IPv4 address.
// "IPv6" if the input is a valid IPv6 address.
// "Neither" if it is neither a valid IPv4 nor IPv6 address.

// Example Cases
// Example 1:
// Input: "192.168.1.1"
// Output: "IPv4"
// (Valid IPv4 address with four octets in the range [0,255].)

// Example 2:
// Input: "2001:0db8:85a3:0000:0000:8a2e:0370:7334"
// Output: "IPv6"
// (Valid IPv6 address with eight hexadecimal groups.)

// Example 3:
// Input: "256.256.256.256"
// Output: "Neither"
// (Invalid IPv4 address because values exceed 255.)

// Example 4:
// Input: "1.1.1"
// Output: "Neither"
// (Invalid IPv4 address because it has only three octets instead of four.)

// Example 5:
// Input: "2001:db8::85a3::8a2e:370:7334"
// Output: "Neither"
// (Invalid IPv6 address because it contains two consecutive ::.)

// Constraints
// The input string consists only of printable ASCII characters.
// The input does not contain leading or trailing spaces.
// has context menu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Node
{
    char str[5];
    struct Node *next;
} node;

node *createNode(char *value)
{
    node *newNode = (node *)malloc(sizeof(node));
    strncpy(newNode->str, value, 4);
    newNode->str[4] = '\0';
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

    node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

int isvalid4(node *head)
{
    node *curr = head;
    while (curr)
    {
        int len = strlen(curr->str);

        for (int i = 0; i < len; i++)
        {
            if (!isdigit(curr->str[i]))
            {
                return 0;
            }
        }

        int num = atoi(curr->str);

        if (num < 0 || num > 255)
        {
            return 0;
        }

        if (len > 1 && curr->str[0] == '0')
        {
            return 0;
        }

        curr = curr->next;
    }
    return 1;
}

int isvalid8(node *head)
{
    node *curr = head;
    while (curr)
    {
        int len = strlen(curr->str);

        if (len < 1 || len > 4)
        {
            return 0;
        }

        for (int i = 0; i < len; i++)
        {
            if (!isxdigit(curr->str[i]))
            {
                return 0;
            }
        }

        curr = curr->next;
    }
    return 1;
}

int main()
{
    char input[MAX];
    node *head = NULL;
    int index = 0;

    printf("Enter the address\n");
    scanf("%s", input);

    char delimiter = (strchr(input, '.') != NULL) ? '.' : ':';
    char *token = strtok(input, &delimiter);
    while (token != NULL)
    {
        node *newNode = createNode(token);
        insertNode(&head, newNode);
        token = strtok(NULL, &delimiter);
        index++;
    }

    if (index == 4)
    {
        if (isvalid4(head))
        {
            printf("IPv4\n");
            return 0;
        }
    }
    else if (index == 8)
    {
        if (isvalid8(head))
        {
            printf("IPv6\n");
            return 0;
        }
    }

    printf("Neither\n");
    return 0;
}
