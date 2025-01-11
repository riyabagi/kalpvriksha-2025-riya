#include <stdio.h>
#include <stdlib.h>

void input(int size, int *matrix) 
{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col ++)
        {
            scanf("%d", &matrix[row * size + col]);
        }
    }
}

void printMatrix(int size, int *matrix)
{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col ++)
        {
            printf("%d ", *(matrix + (row * size) + col));
        }
        printf("\n");
    }
}

void printDiagonals(int size, int *matrix)
{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col ++)
        {
            if( row == col)
            {
                printf("%d ", *(matrix + (row * size) + col));
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    printf("Enter the row and column of matrix\n");
    scanf("%d %d", &row, &col);

    if(row != col)
    {
        printf("It is not a square matrix\nEnter a square matrix");
        return 1;
    }

    int *matrix = (int *) malloc (row * row * sizeof(int *));
    input(row, matrix);
    printMatrix(row, matrix);
    printDiagonals(row, matrix);

    free(matrix);

    return 0;
}
