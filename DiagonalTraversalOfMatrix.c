#include <stdio.h>
#include <stdlib.h>

void input(int size, int *matrix)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            scanf("%d", &matrix[row * size + col]);
        }
    }
}

void traverseMatrix(int size, int *matrix)
{
    printf("Diagonal Traversal of the matrix:\n");
    printf("[ \n");

    for (int colIndex = 0; colIndex < size; colIndex++)
    {
        int row = 0, col = colIndex;
        printf("[ ");
        while (col >= 0)
        {
            printf("%d ", *(matrix+ (row * size )+ col));
            row++;
            col--;
        }
        printf("]\n");
    }

    for (int rowIndex = 1; rowIndex < size; rowIndex++)
    {
        int row = rowIndex, col = size - 1;
        printf("[ ");
        while (row < size)
        {
            printf("%d ", *(matrix+ (row * size )+ col));
            row++;
            col--;
        }
        printf("]\n");
    }
    printf("]\n");
}

int main()
{
    int row, col;
    printf("Enter the row and column of matrix\n");
    scanf("%d %d", &row, &col);

    if (row < 1 && col < 1)
    {
        printf("Enter valid matrix row and column");
        return 1;
    }

    if (row != col)
    {
        printf("It is not a square matrix\nEnter a square matrix");
        return 1;
    }

    int *matrix = (int *)malloc(row * row * sizeof(int *));
    input(row, matrix);
    traverseMatrix(row, matrix);
    return 0;
}
