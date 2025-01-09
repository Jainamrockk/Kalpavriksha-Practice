#include<stdio.h>
#include<stdlib.h>
int totalRows,totalColumns;
int** matrix;

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inputMatrix()
{
    scanf("%d%d",&totalRows,&totalColumns);
    matrix = (int**)malloc(totalRows*sizeof(int*));
    for(int row=0;row<totalRows;row++)
    {
        matrix[row] = (int*)malloc(totalColumns*sizeof(int));
        for(int col = 0;col<totalColumns;col++)
        {
            scanf("%d",&matrix[row][col]);
        }
    }
}

void rotateMatrixClockwise()
{
    int top = 0,bottom=totalRows-1,left = 0,right=totalColumns-1;
while(top<=bottom && left<=right)
{
    for(int index = top;index<bottom;i++)
    {
        swap(&matrix[index][left],&matrix[index+1][left]);
    }
    for(int index=left;index<right;index++)
    {
        swap(&matrix[bottom][index],&matrix[bottom][index+1]);
    }
    for(int index = bottom;index>top;index--)
    {
        swap(&matrix[index][right],&matrix[index-1][right]);
    }
    for(int index=right;index>left+1;index--)
    {
        swap(&matrix[top][index],&matrix[top][index-1]);
    }
    top++;
    bottom--;
    left++;
    right--;
}
}
void printMatrix()
{
    for(int i=0;i<totalRows;i++)
    {
        for(int j=0;j<totalColumns;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void solution()
{
    inputMatrix();
    rotateMatrixClockwise();
    printMatrix();
}


int main()
{
    solution();
    return 0;
}