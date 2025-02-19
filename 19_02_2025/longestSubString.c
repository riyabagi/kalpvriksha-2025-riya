// Input: s = "eceba", K = 2
// Output: 3

#include <stdio.h>
#include <string.h>

void longestSubString(char input[], int k)
{
    int freq[256] = {0};
    int right = 0, left = 0, distinctCount = 0, max = 0;
    int size = strlen(input);

    while (right < size)
    {
        if (freq[input[right]] == 0)
        {
            distinctCount++;
        }
        freq[input[right]]++;
        right++;

        while (distinctCount > k)
        {
            freq[input[left]]--;
            if (freq[input[left]] == 0)
            {
                distinctCount--;
            }
            left++;
        }

        if (k == distinctCount)
        {
            if (max < right - left)
            {
                max = right - left;
            }
        }
    }
    printf("Longest Sub String %d: \n", max);
}

int main()
{
    int k;
    char input[100];
    printf("Enter the string\n");
    scanf("%s", input);

    printf("Enter the k value\n");
    scanf("%d", &k);

    longestSubString(input, k);
    return 0;
}