#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_CHAR 256

char *minWindow(char *input, char *string)
{
    int size1 = strlen(input);
    int size2 = strlen(string);

    if (size1 == 0 || size2 == 0)
    {
        return "";
    }
    if (size1 < size2)
    {
        return "";
    }

    int hash_input[100] = {0};
    int hash_string[100] = {0};

    for (int index = 0; index < size2; index++)
    {
        hash_string[string[index]]++;
    }

    int requiredCount = size2;
    int left = 0, right = 0;
    int minStart = 0, minLen = INT_MAX;

    while (right < size1)
    {
        char ch = input[right];

        if (hash_string[ch] > 0)
        {
            if (hash_input[ch] < hash_string[ch])
            {
                requiredCount--;
            }
        }

        hash_input[ch]++;

        while (requiredCount == 0)
        {
            if (minLen > right - left + 1)
            {
                minLen = right - left + 1;
                minStart = left;
            }

            char ch_l = input[left];

            hash_input[ch_l]--;
            if (hash_string[ch_l] > 0 && hash_input[ch_l] < hash_string[ch_l])
            {
                requiredCount++;
            }

            left++;
        }

        right++;
    }

    if (minLen == INT_MAX)
        return "";

    char *result = (char *)malloc((minLen + 1) * sizeof(char));
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return "";
    }

    strncpy(result, input + minStart, minLen);
    result[minLen] = '\0';

    return result;
}

int main()
{

    char input[101];
    printf("Enter the input string\n");
    scanf("%s", input);

    char string[101];
    printf("Enter the input string\n");
    scanf("%s", string);

    char *result = minWindow(input, string);
    if (strlen(result) == 0)
    {
        printf("No valid window found.\n");
    }
    else
    {
        printf("Minimum window substring: %s\n", result);
    }
    return 0;
}