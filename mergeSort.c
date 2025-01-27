// Problem Description: Write a program to implement the Merge Sort algorithm to sort an array of integers in ascending order. The program should accept the size of the array and its elements as input, and then output the sorted array.

// Time Complexity:
//Best Case: O(nlogn)
//Worst Case: O(nlogn)
//Average Case: O(nlogn)

//Space Complexity:
//Total Space: O(n)

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right)
{
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;

    int *Left = (int *)malloc(leftArraySize * sizeof(int));
    int *Right = (int *)malloc(rightArraySize * sizeof(int));

    for (int index = 0; index < leftArraySize; index++)
        *(Left + index) = *(arr + left + index);
    for (int index2 = 0; index2 < rightArraySize; index2++)
        *(Right + index2) = *(arr + mid + 1 + index2);

    int index = 0, index2 = 0, mergedIndex = left;

    while (index < leftArraySize && index2 < rightArraySize)
    {
        if (*(Left + index) <= *(Right + index2))
        {
            *(arr + mergedIndex++) = *(Left + index++);
        }
        else
        {
            *(arr + mergedIndex++) = *(Right + index2++);
        }
    }

    while (index < leftArraySize)
    {
        *(arr + mergedIndex++) = *(Left + index++);
    }

    while (index2 < rightArraySize)
    {
        *(arr + mergedIndex++) = *(Right + index2++);
    }

    free(Left);
    free(Right);
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter the elements of the array:\n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", (arr + index));
    }

    mergeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int index = 0; index < size; index++)
    {
        printf("%d ", *(arr + index));
    }
    printf("\n");

    free(arr);

    return 0;
}
