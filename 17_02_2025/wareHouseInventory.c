// 2. Warehouse Inventory Tracking System
// You are building a warehouse inventory system to track item quantities. The system supports
// adding items, updating quantities, and querying the quantity of a specific item.
// • "ADD <item> <quantity>" → Adds a new item with the given quantity. If the item already
// exists, increase its quantity.
// • "UPDATE <item> <quantity>" → Updates the quantity of an existing item to the new
// quantity.
// • "QUERY <item>" → Returns the current quantity of the specified item. If the item does not
// exist, return "Item not found".
// Input:
// The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands.
// The next n lines contain a command of one of the following types
// "ADD <item> <quantity>"
// • "UPDATE <item> <quantity>"
// • "QUERY <item>"
// Output:
// For each "QUERY" command, print the current quantity of the item or "Item not found".

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct wareHouse
{
    int top;
    char item[MAX][50];
    int quantity[MAX];
} stack;

void pushItem(stack *s, char item[], int quantity)
{
    if (s->top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    printf("%d\n",quantity);
    for (int index = 0; index <= s->top; index++)
    {
        if (strcmp(s->item[index], item) == 0)
        {
            strcpy(s->item[s->top], item);
            s->quantity[s->top] += quantity;
            return;
        }
    }
    s->top++;
    strcpy(s->item[s->top], item);
    s->quantity[s->top] = quantity;
}

void updateQuantity(stack *s, char item[], int quantity)
{
    for (int index = 0; index <= s->top; index++)
    {
        if (strcmp(s->item[index], item) == 0)
        {
            s->quantity[index] = quantity;
            return;
        }
    }

    printf("Item not found\n");
}

void queryItem(stack *s, char item[])
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int index = 0; index <= s->top; index++)
    {
        if (strcmp(s->item[index], item) == 0)
        {
            printf("Item: %s, Quantity: %d\n", item, s->quantity[index]);
            return;
        }
    }

    printf("Item not found\n");
}

int main()
{
    stack s;
    s.top = -1;
    int choice = 0, quantity;
    char item[MAX];

    printf("1]Add\n2]Update\n3]Display an item\n4]Exit\n");

    while (choice != 4)
    {
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item:  ");
            scanf("%s", item);
            printf("Enter the quantiya of the item:  ");
            scanf("%d", &quantity);
            pushItem(&s, item, quantity);
            break;

        case 2:
            printf("Enter the item:  ");
            scanf("%s", item);
            printf("Enter the quantiya of the item:  ");
            scanf("%d", &quantity);
            updateQuantity(&s, item, quantity);
            break;

        case 3:
            printf("Enter the item:  ");
            scanf("%s", item);
            queryItem(&s, item);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}