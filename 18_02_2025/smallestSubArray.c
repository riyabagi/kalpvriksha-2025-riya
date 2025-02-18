// Find the Smallest Subarray with All Occurrences of the Most Frequent Element

#include <stdio.h>

int main()
{
    int max = 0, value;
    int freq[100] = {0}, array[100], index = 0;
    int index1 = -1, index2;

    printf("Enter the array\n");
    while (scanf("%d", &array[index]) == 1)
    {
        freq[array[index]]++;
        if (max < freq[array[index]]++)
        {
            max = freq[array[index]]++;
            value = array[index];
        }
        index++;

        if (getchar() == '\n')
        {
            break;
        }
    }

    for (int itr = 0; itr < index; itr++)
    {
        if (array[itr] == value && index1 == -1)
        {
            index1 = itr;
        }

        if (array[itr] == value)
        {
            index2 = itr;
        }
    }

    printf("(%d, %d)", index1, index2);

    return 0;
}