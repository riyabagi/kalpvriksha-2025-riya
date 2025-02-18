// Problem Statement:
// Given a string s and an integer K, find the length of the longest substring that contains exactly K
// distinct characters. If no such substring exists, return -1.
// Input:
// • A string s of length N.
// • An integer K.
// Output:
// • An integer representing the length of the longest substring with exactly K distinct characters.
// Example:
// Input: s = "aabbcc", K = 2
// Output: 4 (aabb is the longest substring with exactly 2 distinct characters.)

#include <stdio.h>
#include <string.h>

#define MAX 100

int findLagrestSubArray(char string[], int len)
{
    int freq[256] = {0};
    int left = 0, right = 0, distinctCount = 0, maxLen = 0;
    int size = strlen(string);

    if (len == 0)
        return -1;

    while (right < size)
    {
        if (freq[string[right]] == 0)
        {
            distinctCount++;
        }

        freq[string[right]]++;
        right++;

        while (distinctCount > len)
        {
            freq[string[left]]--;
            if (freq[string[left]] == 0)
            {
                distinctCount--;
            }
            left++;
        }

        if (distinctCount == len)
        {
            maxLen = (right - left > maxLen) ? (right - left) : maxLen;
        }
    }

    return maxLen;
}

int main()
{
    char string[MAX];
    int len;

    printf("Enter the string\n");
    scanf("%s", string);

    printf("Enter the lelgth\n");
    scanf("%d", &len);

    int result = findLagrestSubArray(string, len);
    printf("The longest substring: %d\n",result);

    return 0;
}