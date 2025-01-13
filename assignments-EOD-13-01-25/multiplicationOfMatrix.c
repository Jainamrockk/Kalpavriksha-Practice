#include <stdio.h>
#include <stdlib.h>

int totalColumns1, totalRows1;
int totalColumns2, totalRows2;
int **matrix3;

void inputMatrix(int **matrix, int totalRows, int totalColumns)
{

    printf("Enter the matrix:\n");
    for (int row = 0; row < totalRows; row++)
    {
        matrix[row] = (int *)malloc(totalColumns * sizeof(int));
        for (int col = 0; col < totalColumns; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
}
void multiplyMatrices(int** matrix1,int** matrix2)
{
    for(int row = 0;row<totalRows1;row++)
    {
            matrix3[row] = (int*)malloc(totalColumns2*sizeof(int));
        for(int col = 0;col<totalColumns2;col++)
        {
            int valueAtIndex = 0;
            for(int val=0;val<totalColumns1;val++)
            {
                valueAtIndex+=matrix1[row][val]*matrix2[val][col];
            }
            matrix3[row][col] = valueAtIndex;
        }
    }
}
void printMatrix(int** matrix,int totalRows,int totalColumns)
{
    for(int row=0;row<totalRows;row++)
    {
        for(int col=0;col<totalColumns;col++)
        {
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }
}
int main()
{
    int **matrix1,**matrix2;
    printf("Enter Parameters for Matrix 1:\n");
    scanf("%d%d", &totalRows1, &totalColumns1);
    matrix1 = (int **)malloc(totalRows1 * sizeof(int *));
    inputMatrix(matrix1, totalRows1, totalColumns1);
    printf("Enter Parameters for Matrix 2:\n");
    scanf("%d%d", &totalRows2, &totalColumns2);
    matrix2 = (int **)malloc(totalRows2 * sizeof(int *));
    inputMatrix(matrix2, totalRows2, totalColumns2);
    if (totalColumns1 != totalRows2)
    {
        printf("Enter the matrices such that columns of matrix 1 == rows of matrix 2\n");
        return 0;
    }
    matrix3 = (int **)malloc(totalRows1* sizeof(int *));
    multiplyMatrices(matrix1, matrix2);
    printMatrix(matrix3, totalRows1, totalColumns2);
    return 0;
}