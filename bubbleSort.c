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
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }

    printf("Original Array:\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted Array:\n");
    printArray(arr, size);

    free(arr);

    return 0;
}
