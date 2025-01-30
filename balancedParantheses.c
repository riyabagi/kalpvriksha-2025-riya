#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50];
    char *arr = (char*) malloc(50 * sizeof(char));
    printf("Enter the elements to add in stack\n");
    fgets(input, 50, stdin);

    int count = 0;
    int flag = 1;

    input[strcspn(input, "\n")] = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        char token = input[i];

        if (token == '(' || token == '[' || token == '{')
        {
            *(arr + count) = token;
            count++;
        }
        else if (token == ')')
        {
            if (count == 0 || *(arr + count - 1) != '(')
            {
                flag = 0;
                break;
            }
            else
            {
                count--;
            }
        }
        else if (token == '}')
        {
            if (count == 0 || *(arr + count - 1) != '{')
            {
                flag = 0;
                break;
            }
            else
            {
                count--;
            }
        }
        else if (token == ']')
        {
            if (count == 0 || *(arr + count - 1) != '[')
            {
                flag = 0;
                break;
            }
            else
            {
                count--;
            }
        }
    }

    if (count == 0 && flag)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    free(arr);
    return 0;
}
