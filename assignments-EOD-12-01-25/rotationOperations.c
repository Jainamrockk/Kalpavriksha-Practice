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

int** matrix;
void inputMatrix(int* totalRows,int* totalColumns)
{
    printf("Enter Number of Rows:");
    scanf("%d",totalRows);
    printf("Enter Number of Columns:");
    scanf("%d",totalColumns);
    printf("Enter Matrix:\n");
    matrix = (int**)malloc(*totalRows*sizeof(int*));
    for(int row=0;row<(*totalRows);row++)
    {
    matrix[row] = (int*)malloc(*totalColumns*sizeof(int));
        for(int column = 0;column<(*totalColumns);column++)
        {
            scanf("%d",&matrix[row][column]);
        }
    }

}
void printMatrix(int* totalRows,int* totalColumns)
{
     for(int row=0;row<(*totalRows);row++)
    {
        for(int column = 0;column<(*totalColumns);column++)
        {
            printf("%d ",matrix[row][column]);
        }
        printf("\n");
    }

}

void swap(int* num1,int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void transposeMatrix(int** transpose,int totalRows,int totalColumns)
{
    for(int col=0;col<totalColumns;col++)
    {
        for(int row = 0;row<totalRows;row++)
        {
            transpose[col][row] = matrix[row][col];
        }
    }
}
void reverseMatrix(int** transpose,int totalRows,int totalColumns)
{
    for(int col=0;col<totalColumns;col++)
    {
        for(int row = 0;row<totalRows/2;row++)
        {
            swap(&transpose[col][row],&transpose[col][totalRows-1-row]);
        }
    }
}

void assignMatrix(int** transpose,int totalRows,int totalColumns)
{
    matrix = (int**)realloc(matrix,totalRows*sizeof(int*));
    for(int row=0;row<totalRows;row++)
    {
        matrix[row] = (int*)malloc(totalColumns*sizeof(int));
        for(int col=0;col<totalColumns;col++)
        {
            matrix[row][col] = transpose[row][col];
        }
    }
}
void rotateMatrix(int* totalRows,int* totalColumns)
{
    int **transpose = (int**)malloc(*totalColumns*sizeof(int*));
    for(int index=0;index<*totalColumns;index++)
    {
        transpose[index] = (int*)malloc(*totalRows*sizeof(int));
    }
    transposeMatrix(transpose,*totalRows,*totalColumns);
    reverseMatrix(transpose,*totalRows,*totalColumns);
    swap(totalColumns,totalRows);
    assignMatrix(transpose,*totalRows,*totalColumns);

}
void rotateRowsRight(int totalRows,int totalColumns,int steps)
{
    for(int rows = 0;rows<totalRows;rows++)
    {
        for(int col = totalColumns-1;col>=0;col--)
        {
            swap(&matrix[rows][0],&matrix[rows][(col+steps)%totalColumns]);
        }
    }
}
void rotateRowsLeft(int totalRows,int totalColumns,int steps)
{
    for(int rows = 0;rows<totalRows;rows++)
    {
        for(int col = 0;col<totalColumns;col++)
        {
            swap(&matrix[rows][totalColumns-1],&matrix[rows][(totalColumns+(col-steps%totalColumns))%totalColumns]);
        }
    }
}

void rotateColumnsUp(int totalRows,int totalColumns,int steps)
{
    for(int col=0;col<totalColumns;col++)
    {
        for(int row=totalRows-1;row>=0;row--)
        {
            swap(&matrix[totalRows-1][col],&matrix[(row+steps)%totalRows][col]);
        }
    }
}

void rotateColumnsDown(int totalRows,int totalColumns,int steps)
{
    for(int col=0;col<totalColumns;col++)
    {
        for(int row=0;row<totalRows;row++)
        {
            swap(&matrix[0][col],&matrix[(totalRows+(row-steps%totalRows))%totalRows][col]);
        }
    }
}
void solution()
{
    int totalRows,totalColumns;
    inputMatrix(&totalRows,&totalColumns);
    printf("Your Input Matrix is:\n");
    printMatrix(&totalRows,&totalColumns);
    int choice,steps;
    while(1)
    {
        printf("Enter the operation you want to perform:\n");
        printf("1.Matrix Level Rotation.\n");
        printf("2.Rotate all the rows to Left.\n");
        printf("3.Rotate all the rows to Right.\n");
        printf("4.Rotate all the columns to Up.\n");
        printf("5.Rotate all the columns to Down.\n");
        printf("Else any key to Exit\n\n");
        printf("Enter Your  Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            rotateMatrix(&totalRows,&totalColumns);
            printf("Your Updated Matrix is:\n");
            printMatrix(&totalRows,&totalColumns);
            break;
            case 2:
            printf("Enter the specified number of steps by which you have to rotate the matrix to Left:");
            scanf("%d",&steps);
            rotateRowsLeft(totalRows,totalColumns,steps);
            printf("Your Updated Matrix is:\n");
            printMatrix(&totalRows,&totalColumns);
            break;
            case 3:
            printf("Enter the specified number of steps by which you have to rotate the matrix to Right:");
            scanf("%d",&steps);
            rotateRowsRight(totalRows,totalColumns,steps);
            printf("Your Updated Matrix is:\n");
            printMatrix(&totalRows,&totalColumns);
            break;
            case 4:
            printf("Enter the specified number of steps by which you have to rotate the matrix to Up:");
            scanf("%d",&steps);
            rotateColumnsUp(totalRows,totalColumns,steps);
            printf("Your Updated Matrix is:\n");
            printMatrix(&totalRows,&totalColumns);
            break;
            case 5:
            printf("Enter the specified number of steps by which you have to rotate the matrix to Down:");
            scanf("%d",&steps);
            rotateColumnsDown(totalRows,totalColumns,steps);
            printf("Your Updated Matrix is:\n");
            printMatrix(&totalRows,&totalColumns);
            break;
            default:
            return;   
        }

    }

}

int main()
{
    solution();
    return 0;
}