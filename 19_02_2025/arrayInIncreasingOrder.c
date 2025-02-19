// minimum Operations to Make the Array Increasing

#include <stdio.h>

int minOperations(int *array, int size)
{
    int count = 0;
    
    for (int index = 1; index < size; index++)
    {
        if (array[index] <= array[index - 1])
        {
            int diff = (array[index - 1] - array[index]) + 1; 
            array[index] += diff;
            count += diff;
        }
    }
    
    return count;
}


int main()
{
    int array[10], size;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    for (int index = 0; index < size; index++)
    {
        scanf("%d", &array[index]);
    }

    int count = minOperations(array, size);
    printf("Minimum operation required are : %d", count);

    return 0;
}