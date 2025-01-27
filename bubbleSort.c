//problem statement : Write a program to implement the Bubble Sort algorithm to sort a given array of integers in ascending order.

//Bubble Sort Algorithm: Compare adjacent elements in the array. Swap them if they are out of order.

//Time Complexity: Best Case (Already Sorted): 𝑂(𝑛) Average Case: O(n^2) Worst Case (Reverse Sorted): O(n^2)

//Space Complexity: 𝑂(𝑛): as we don't require an extra space

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        int swapped = 0;

        for (int index2 = 0; index2 < size - index - 1; index2++)
        {
            if (*(arr + index2) > *(arr + index2 + 1))
            {
                int temp = *(arr + index2);
                *(arr + index2) = *(arr + index2 + 1);
                *(arr + index2 + 1) = temp;

                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void printArray(int *arr, int size)
{
    for (int index = 0; index < size; index++)
    {
        printf("%d ", *(arr + index));
    }
    printf("\n");
}

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if(size < 1)
    {
        printf("Enter valid size");
        return 0;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int index = 0; index < size; index++)
    {
        scanf("%d", (arr + index));
    }

    printf("Original Array:\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted Array:\n");
    printArray(arr, size);

    free(arr);

    return 0;
}
