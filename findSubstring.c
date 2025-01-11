#include <stdio.h>
#include <stdlib.h>

int findSubstring(char *sentence, char *subString)
{
    for (int index = 0; sentence[index] != '\0'; index++)
    {
        if (*(sentence + index) == *(subString)) 
        {
            int idx = 0;
            while (*(subString + idx) != '\0' && *(sentence + index + idx) == *(subString + idx)) 
            {
                idx++; 
            }

            if (*(subString + idx) == '\0') 
            {
                printf("%d", index); 
                return 0; 
            }
        }
    }
    return -1;
}

int main()
{
    char *sentence = (char *)calloc(101, (sizeof(char)));
    char *subString = (char *)calloc(101, (sizeof(char)));
    if (!sentence || !subString) 
    {
        printf("Memory Allocation failed");
        return 1;
    }
    printf("Enter the sentence\n");
    fgets(sentence, 101, stdin);
    printf("Enter the subString\n");
    scanf("%100s", subString);

    if (findSubstring(sentence, subString) == -1)
    {
        printf("Substring not found.\n");
    }

    free(sentence);
    free(subString);

    return 0;
}
