#include <stdio.h>
#include <stdlib.h>

void readData(int row, int *matrix)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row; colIndex++)
        {
            scanf("%d", &matrix[rowIndex * row + colIndex]);
        }
    }
}

void printMatrix(int row, int *matrix)
{
    printf("The matrix is \n");

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row; colIndex++)
        {
            printf("%d ", *(matrix + (rowIndex * row) + colIndex));
        }
        printf("\n");
    }
}

void transposeMatrix(int row, int *matrix)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = rowIndex + 1; colIndex < row; colIndex++)
        {
            int temp = *(matrix + (rowIndex * row) + colIndex);
            *(matrix + (rowIndex * row) + colIndex) = *(matrix + (colIndex * row) + rowIndex);
            *(matrix + (colIndex * row) + rowIndex) = temp;
        }
    }
}

void printTranspose(int row, int *matrix)
{
    printf("The transpose of matrix is \n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row; colIndex++)
        {
            printf("%d ", *(matrix + (rowIndex * row) + colIndex));
        }
        printf("\n");
    }
}

void inverseMatrix(int row, int *matrix)
{
    printf("Rotated matrix \n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row / 2; colIndex++)
        {
            int temp = *(matrix + (rowIndex * row) + colIndex);
            *(matrix + (rowIndex * row) + colIndex) = *(matrix + (rowIndex * row) + row - colIndex - 1);
            *(matrix + (rowIndex * row) + row - colIndex - 1) = temp;
        }
    }
}

void printInverseMatrix(int row, int *matrix)
{
    printf("the transpose of matrix is \n");
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < row; colIndex++)
        {
            printf("%d ", *(matrix + (rowIndex * row) + colIndex));
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter size\t");
    scanf("%d", &size);

    int *matrix = (int *)malloc(size * size * sizeof(int));

    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    readData(size, matrix);
    printMatrix(size, matrix);
    transposeMatrix(size, matrix);
    printTranspose(size, matrix);
    inverseMatrix(size, matrix);
    printInverseMatrix(size, matrix);

    free(matrix);
    return 0;
}
