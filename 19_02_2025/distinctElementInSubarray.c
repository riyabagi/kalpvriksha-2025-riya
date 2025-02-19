#include <stdio.h>
#include <string.h> 

void distinctElement(int *array, int size, int k)
{
    int result[100], idx = 0;
    int hasmap[100] = {0};
    int right = k;

    for (int left = 0; left <= size - k; left++)
    {
        int count = 0;
        for (int index = left; index < right; index++)
        {
            if (hasmap[array[index]] == 0)
            {
                count++;
            }
            hasmap[array[index]]++;
        }
        
        memset(hasmap, 0, sizeof(hasmap));
        result[idx++] = count;
        right++;
    }

    for (int index = 0; index < idx; index++)
    {
        printf("%d ", result[index]);
    }
    printf("\n");
}

int main()
{
    int array[10], size, k;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    for (int index = 0; index < size; index++)
    {
        scanf("%d", &array[index]);
    }

    printf("Enter the value of k to group into subarray\n");
    scanf("%d", &k);

    if (k > size)
    {
        printf("Dividing into subarray is not possible\n");
        return 0;
    }

    distinctElement(array, size, k);

    return 0;
}