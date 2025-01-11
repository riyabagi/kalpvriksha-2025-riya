#include <stdio.h>
#include <stdlib.h>

void readInput(int *row, int *col)
{
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", row, col);
}

void readElements(int row, int col, int *matrix)
{
    printf("Enter the elements of the matrix:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            scanf("%d", &matrix[rowIndex * col + colIndex]);
        }
    }
}

void findsum(int row, int col, int *matrix)
{
    int allsum = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            allsum += *(matrix + (rowIndex * col) + colIndex);
        }
    }

    printf("Sum of all values: %d\n", allsum);
}

void findrowsum(int row, int col, int *matrix)
{
    printf("Row-wise sum is:\n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int rowsum = 0;
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            rowsum += *(matrix + (rowIndex * col) + colIndex);
        }
        printf("%d\n", rowsum);
    }
}

int main()
{
    int row, col;

    readInput(&row, &col);

    int *matrix = (int *)malloc(row * col * sizeof(int));
    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    readElements(row, col, matrix);

    findsum(row, col, matrix);

    findrowsum(row, col, matrix);

    free(matrix);
    return 0;
}
