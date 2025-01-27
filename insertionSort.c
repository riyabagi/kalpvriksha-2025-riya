// Problem Description: Write a program to implement the Insertion Sort algorithm to sort an array of integers in ascending order. The program should accept the size of the array and its elements as input, and then output the sorted array.

// Time Complexity:
// Best Case (Already Sorted Array): O(n)
// Worst Case (Reverse Sorted Array): O(n^2)
// Average Case: O(n^2)

// Space Complexity:
// Auxiliary Space: O(1)
  
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int size, int *arr)
{
    for (int index = 1; index < size; index++)
    {
        int current = *(arr + index);
        int index2 = index - 1;
        while (index2 >= 0 && *(arr + index2) > current)
        {
            *(arr + index2 + 1) = *(arr + index2);
            index2--;
        }
        *(arr + index2 + 1) = current;
    }
}

void printArray(int size, int *arr)
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
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Enter valid size\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int index = 0; index < size; index++)
    {
        scanf("%d", (arr + index));
    }

    insertionSort(size, arr);
    printArray(size, arr);
    
    free(arr);

    return 0;
}
