/*
2d Array  
Question:
Write a C program to perform various rotation operations on a 2D matrix based
on user input. The program should display a menu with the following options:
Matrix-Level Rotation: Rotate the entire matrix 90° clockwise.
Row-Wise Rotation (Left): Rotate all rows of the matrix to the left by a specified number of steps.
Row-Wise Rotation (Right): Rotate all rows of the matrix to the right by a specified number of steps.
Column-Wise Rotation (Up): Rotate all columns of the matrix upwards by a specified number of steps.
Column-Wise Rotation (Down): Rotate all columns of the matrix downwards by a specified number of steps.
The program should prompt the user to enter the size of the matrix, the elements of the matrix, and the
number of steps (d) for the rotation. After performing the selected operation, display the resulting matrix.
Allow the user to repeat the process until they choose to exit. */
 
#include<stdio.h>
#include<stdlib.h>
 
int totalRows,totalColumns;
int** matrix;
int** transpose;
void inputMatrix()
{
    scanf("%d%d",&totalRows,&totalColumns);
    matrix = (int**)malloc(totalRows*sizeof(int*));
    for(int row = 0;row<totalRows;row++)
    {
        matrix[row] = (int*)calloc(totalColumns,sizeof(int));
        for(int col = 0;col<totalColumns;col++)
        {
            scanf("%d",&matrix[row][col]);
        }
    }
}
void swap(int* num1,int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void transposeMatrix()
{
     transpose = (int**)malloc(totalColumns*sizeof(int*));
     for(int row=0;row<totalColumns;row++)
     {
         transpose[row] = (int*)malloc(totalRows*sizeof(int));
         for(int col=0;col<totalRows;col++)
         {
             transpose[row][col] = matrix[col][row];
         }
     }
     matrix = (int**)realloc(matrix,totalColumns*sizeof(int*));
     for(int row=0;row<totalColumns;row++)
     {
         matrix[row] = (int*)calloc(totalRows,sizeof(int));
         matrix[row] = transpose[row];
     }
     swap(&totalRows,&totalColumns);
}
 
void matrixLevelRotation()
{
    transposeMatrix();
    for(int row =0;row<totalRows;row++)
    {
        int left = 0;
        int right = totalColumns-1;
        while(left<right)
        {
            swap(&matrix[row][left],&matrix[row][right]);
            left++;
            right--;
        }
    }
}
void printMatrix()
{
    for(int row =0;row<totalRows;row++)
    {
        for(int col=0;col<totalColumns;col++)
        {
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }
}
void rotateRowRight(int d)
{
    for(int row=0;row<totalRows;row++)
    {
        int* temp = (int*)calloc(totalColumns,sizeof(int));
        for(int col = 0;col<totalColumns;col++)
        {
            temp[col] = matrix[row][(totalColumns+col-d%totalColumns)%totalColumns];
        }
        matrix[row] = temp;
    }
}
void rotateRowLeft(int d)
{
    for(int row=0;row<totalRows;row++)
    {
        int* temp = (int*)calloc(totalColumns,sizeof(int));
        for(int col = 0;col<totalColumns;col++)
        {
            temp[col] = matrix[row][(col+d%totalColumns)%totalColumns];
        }
        matrix[row] = temp;
    }
}
 
void rotateColumnUp(int d)
{
     for(int col=0;col<totalColumns;col++)
    {
        int* temp = (int*)calloc(totalRows,sizeof(int));
        for(int row = 0;row<totalRows;row++)
        {
            temp[row] = matrix[(row+d%totalRows)%totalRows][col];
        }
        for(int row = 0;row<totalRows;row++)
        {
            matrix[row][col] = temp[row];
        }
    }
}
void rotateColumnDown(int d)
{
     for(int col=0;col<totalColumns;col++)
    {
        int* temp = (int*)calloc(totalRows,sizeof(int));
        for(int row = 0;row<totalRows;row++)
        {
            temp[row] = matrix[(totalRows+row-d%totalRows)%totalRows][col];
        }
        for(int row = 0;row<totalRows;row++)
        {
            matrix[row][col] = temp[row];
        }
    }
}
int main()
{
 
    inputMatrix();
    printMatrix();
    while(1)
    {
        printf("Enter  the Operation to be performed:\n");
        printf("1.Matrix-Level Rotation.\n");
        printf("2.Rotate all rows of the matrix to the left by a specified number of steps.\n");
        printf("3.Rotate all rows of the matrix to the right by a specified number of steps.\n");
        printf("4.Rotate all columns of the matrix up by a specified number of steps.\n");
        printf("5.Rotate all columns of the matrix down by a specified number of steps.\n");
        printf("Else Exit.\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            matrixLevelRotation();
            printMatrix();
            break;
            int d;
            printf("Enter Steps:");
            case 2:
            scanf("%d",&d);
            rotateRowLeft(d);
            printMatrix();
            break;
            case 3:
            scanf("%d",&d);
            rotateRowRight(d);
            printMatrix();
            break;
            case 4:
            scanf("%d",&d);
            rotateColumnUp(d);
            printMatrix();
            break;
            case 5:
            scanf("%d",&d);
            rotateColumnDown(d);
            printMatrix();
            break;
            default:
            return 0;
        }
    }
}