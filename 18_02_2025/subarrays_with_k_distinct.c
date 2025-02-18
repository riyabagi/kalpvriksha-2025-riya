#include <stdio.h>
#include <string.h>

#define MAX 100

int distinctSubArray(int input[], int len, int size)
{
    int freq[100] = {0};
    int left = 0, right = 0, distinctCount = 0, count = 0;

    if (len <= 0)
    {
        printf("Invalid length size\n");
        return 0;
    }

    while (right < size)
    {
        if (freq[input[right]] == 0)
        {
            distinctCount++;
        }

        freq[input[right]]++;

        while (distinctCount > len)
        {
            freq[input[left]]--;
            if (freq[input[left]] == 0)
            {
                distinctCount--;
            }
            left++;
        }

        if (distinctCount == len)
        {
            count += (right - left + 1);
        }

        right++;
    }

    return count;
}

int main()
{
    int input[MAX];
    int len, index = 0, value;

    printf("Enter the input array\n");

    while (scanf("%d", &input[index++]) == 1)
    {
        if (getchar() == '\n')
        {
            break;
        }
    }

    int size = index;
    printf("Enter the length\n");
    scanf("%d", &len);

    int result = distinctSubArray(input, len, size);
    printf("The number of subarrays with exactly %d distinct integers: %d\n", len, result);

    return 0;
}