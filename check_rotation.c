#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_rotation(char *word1, char *word2)
{
    for (int index = 0; word1[index] != '\0'; index++)
    {
        if (*(word1 + index) == *(word2))
        {
            int word1Index = index;
            int idx = 0;
            while (*(word2 + idx) != '\0' && *(word1 + word1Index) == *(word2 + idx))
            {
                idx++;
                word1Index++;

                if (word1Index >= strlen(word1))
                {
                    word1Index = 0;
                }
            }

            if (*(word2 + idx) == '\0')
            {
                printf("True");
                return;
            }
        }
    }
    printf("False");
}

int main()
{
    char *word1 = (char *)calloc(101, (sizeof(char)));
    char *word2 = (char *)calloc(101, (sizeof(char)));
    if (!word1 || !word2)
    {
        printf("Memory Allocation failed");
        return 1;
    }
    printf("Enter the 1st word\n");
    scanf("%s", word1);
    printf("Enter the 2nd word \n");
    scanf("%s", word2);

    if (strlen(word1) != strlen(word2))
    {
        printf("False\n");
        return 0;
    }

    check_rotation(word1, word2);

    free(word1);
    free(word2);

    return 0;
}
