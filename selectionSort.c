// Problem Statement : Implement the Selection Sort algorithm to sort an array of integers in ascending order.
// Total Time Complexity:O(n^2)
// Space Complexity: O(1)


#include <stdlib.h>
#include <stdio.h>

void printList(int *arr, int size)
{
    for (int index = 0; index < size; index++)
    {
        printf("%d ", *(arr + index));
    }
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    for (int index1 = 0; index1 < size; index1++)
    {
        for (int index2 = index1 + 1; index2 < size; index2++)
        {
            if (*(arr + index2) < *(arr + index1))
            {
                int temp = *(arr + index1);
                *(arr + index1) = *(arr + index2);
                *(arr + index2) = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the size\n");
    scanf("%d", &size);

    if (size < 1)
    {
        printf("Enter valid size\n");
        return 0;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int index = 0; index < size; index++)
    {
        scanf("%d", (arr + index));
    }

    printf("The origional array\n");
    printList(arr, size);

    selectionSort(arr, size);

    printf("Sorted Array:\n");
    printList(arr, size);

    return 0;
}
