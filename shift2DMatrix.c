#include <stdio.h>
#include <stdlib.h>

void input(int size, int *matrix)
{
    printf("Enter the elements\n");
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            scanf("%d", &matrix[row * size + col]);
        }
    }
}

void printMatrix(int sizerow, int sizecol, int *matrix)
{
    for (int row = 0; row < sizerow; row++)
    {
        for (int col = 0; col < sizecol; col++)
        {
            printf("%d ", *(matrix + (row * sizerow) + col));
        }
        printf("\n");
    }
}

void shiftMatrix(int sizerow, int sizecol, int *matrix, int shift, int *shiftedMatrix)
{
    int totalElements = sizerow * sizecol;
    shift %= totalElements;

    for (int index = 0; index < totalElements; index++)
    {
        int newPos = (index + shift) % totalElements;
        *(shiftedMatrix + newPos) = *(matrix + index);
    }
    printf("\n");
}

int main()
{
    int row, col, shift;
    printf("Enter the row and column of matrix\n");
    scanf("%d %d", &row, &col);
    printf("Enter the shifting value\n");
    scanf("%d", &shift);

    int *matrix = (int *)malloc(row * row * sizeof(int *));
    input(row, matrix);
    printMatrix(row, col, matrix);

    int *shiftedMatrix = (int *)malloc(row * col * (sizeof(int *)));

    printf("Entered elements are\n");
    shiftMatrix(row, col, matrix, shift, shiftedMatrix);

    printf("Shifted matrix \n");
    printMatrix(row, col, shiftedMatrix);

    free(matrix);
    free(shiftedMatrix);

    return 0;
}
