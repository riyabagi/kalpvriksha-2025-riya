#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int custom_isalpha(char character)
{
    if (character >= 'A' && character <= 'Z') {
        return 1;  
    }
    if (character >= 'a' && character <= 'z') {
        return 1; 
    }
    return 0; 
}
void atoi_function(char *input)
{
    int value = 0, sign = 1, idx = 0;
    if (*(input) == '-')
    {
        sign = -1;
        idx++;
    }
    for (int index = idx; input[index] != '\0'; index++)
    {
        if (custom_isalpha(*(input + index)))
        {
            printf("0");
            return;
        }
        value = value * 10 + (*(input + index) - '0');
    }
    value *= sign;
    printf("%d", value);
}

int main()
{
    char *input = (char *)calloc(101, (sizeof(char)));
    if (!input)
    {
        printf("Memory Allocation failed");
        return 1;
    }
    printf("Give an input\n");
    scanf("%s", input);

    atoi_function(input);

    free(input);

    return 0;
}
