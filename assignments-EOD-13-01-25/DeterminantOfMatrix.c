#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int dimension,int matrix[dimension][dimension])
{
    
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
}
void printMatrix(int dimension,int matrix[dimension][dimension])
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");

    }
}


int findDeterminant(int dimension,int matrix[dimension][dimension])
{
    if(dimension == 0)
    return 0;

    if(dimension == 1)
    return matrix[0][0];

    if(dimension == 2)
    {
        
        return ((matrix[0][0]*matrix[1][1]) - (matrix[1][0]*matrix[0][1]));
    }
  
   
    int determinant = 0,sign=1;
    for(int row = 0;row<dimension;row++)
    {
        int subMatrix[dimension-1][dimension-1];
        int k = 0,l=0;
        for(int idx1 = 0;idx1<dimension;idx1++)
        {
            if(idx1 == row)
            continue;
            for(int idx2 = 1;idx2<dimension;idx2++)
            {
                subMatrix[k][l++] = matrix[idx1][idx2];
            }
            k++;
            l = 0;
        }
        determinant += matrix[row][0]*findDeterminant(dimension-1,subMatrix)*sign;
        sign = -sign;
    }
    return determinant;
}



int main()
{
    int dimension;
    scanf("%d", &dimension);
    int matrix[dimension][dimension];
    inputMatrix(dimension,matrix);
   
    // printf("%d\n",matrix[0][0]);
    int determinant = findDeterminant(dimension,matrix);
    printf("\nDeterminant:%d\n",determinant);
    return 0;
}