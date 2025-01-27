// problem statement: Design and implement a sorting algorithm by using quick sort approach to sort an array of integers.

// Time Complexity:
// Best Case:O(n log n) 
// Average Case: O(n log n).
// Worst Case: O(n²).
  
// Space Complexity:
// O(log n) for balanced partitions.
// O(n) for worst-case unbalanced partitions.

#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int low, int high)
{
    int *pivotElement = arr + high;
    int *smallerElementIndex = arr + low - 1;

    for (int *currentElement = arr + low; currentElement < arr + high; currentElement++)
    {
        if (*currentElement <= *pivotElement)
        {
            smallerElementIndex++;
            swap(smallerElementIndex, currentElement);
        }
    }

    swap(smallerElementIndex + 1, pivotElement);
    return (smallerElementIndex - arr + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int *ptr = arr; ptr < arr + size; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
