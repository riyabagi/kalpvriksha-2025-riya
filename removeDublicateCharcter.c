#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *removeDublicate(char *word, char *newWord)
{
    int newWordIndex = 0;

    for (int index = 0; index < strlen(word); index++)
    {
        int isDuplicate = 0;

        for (int letter = 0; letter < strlen(newWord); letter++)
        {
            if (*(word + index) == *(newWord + letter))
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            *(newWord + newWordIndex) = *(word + index);
            newWordIndex++;
        }
    }
    *(newWord + newWordIndex) = '\0';
    return newWord;
}

int main()
{
    char *word = (char *)malloc(101 * (sizeof(char)));
    char *newWord = (char *)malloc(101 * (sizeof(char)));
    if (!word)
    {
        printf("Memory Allocation failed");
        return 1;
    }
    printf("Enter the word\n");
    scanf("%100s", word);

    char *wordWithoutDuplicateChar = removeDublicate(word, newWord);
    printf("Word without duplicate characters: %s\n", wordWithoutDuplicateChar);

    free(word);

    return 0;
}
