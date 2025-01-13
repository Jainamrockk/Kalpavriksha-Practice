#include<stdio.h>
#include<stdlib.h>
int totalRows,totalColumns;
int** matrix;

void inputMatrix()
{
    matrix = (int**)malloc(totalRows*sizeof(int *));
    for(int row = 0;row<totalRows;row++)
    {
        matrix[row] = (int*)malloc(totalColumns*sizeof(int));
        for(int col=0;col<totalColumns;col++)
        {
            scanf("%d",&matrix[row][col]);
        }
    }
}

void findSaddlePoint()
{
    int lowRow[totalRows];
    int highColumn[totalColumns];
    int flag = 0;
    for(int row=0;row<totalRows;row++)
    {
        int low = 1e9;
        int lowIndex = 0;
        for(int col=0;col<totalColumns;col++)
        {
            if(matrix[row][col]<low)
            {
                low = matrix[row][col];
                lowIndex = row*10+col;
            }
        }
        lowRow[row] = lowIndex;
    }
    for(int col=0;col<totalColumns;col++)
    {
        int maxi =-1e9;
        int maxIndex = 0;
        for(int row=0;row<totalRows;row++)
        {
            if(maxi<matrix[row][col])
            {
                maxi = matrix[row][col];
                maxIndex = row*10+col;
            }
        }
        highColumn[col] = maxIndex;
    }

    for(int row=0;row<totalRows;row++)
    {
        for(int col=0;col<totalColumns;col++)
        {
            if(lowRow[row] == highColumn[col])
            {
                flag = 1;
                int i = (lowRow[row]/10);
                int j = lowRow[row]%10;
                printf("Saddle points is (%d,%d):%d\n",i,j,matrix[i][j]);
            }
        }
    }
    if(flag == 0)
    printf("-1");
}

int main()
{
    scanf("%d%d",&totalRows,&totalColumns);
    inputMatrix();
    findSaddlePoint();

    return 0;
}