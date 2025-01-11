#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char *sentence)
{
    int count = 0;
    int word = 0;

    for (int index = 0; sentence[index] != '\0'; index++)
    {
        if (isalnum(sentence[index]))
        {
            word = 1; 
        }
        else if (word && isspace(sentence[index]))
        {
            count++;
            word = 0; 
        }
    }

    if (word)
    {
        count++;
    }

    printf("%d\n", count);
}

int main()
{
    char *sentence = (char *)calloc(101, (sizeof(char)));
    if (!sentence)
    {
        printf("Memory Allocation failed");
        return 1;
    }
    printf("Enter the word\n");
    fgets(sentence, 101, stdin);

    countWords(sentence);
    free(sentence);

    return 0;
}
