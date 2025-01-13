#include <stdio.h>
#include <stdlib.h>

int cnt=0;
int** inverse;

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


void transpose(int dimension)
{
    for(int row=0;row<dimension;row++)
    {
        for(int col=row+1;col<dimension;col++)
        {
            int temp = inverse[row][col];
            inverse[row][col] = inverse[col][row];
            inverse[col][row] = temp;
        }
    }
}

void evaluateAdjointMatrix(int dimension,int matrix[dimension][dimension])
{
    inverse = (int**)calloc(dimension,sizeof(int*));
    for(int row = 0;row<dimension;row++)
    {
        inverse[row] = (int*)calloc(dimension,sizeof(int));
        for(int col = 0;col<dimension;col++)
        {
            int subMatrix[dimension-1][dimension-1];
            int k = 0,l=0;
            for(int idx1 = 0;idx1<dimension;idx1++)
            {
                if(idx1 == row)
                continue;
                for(int idx2=0;idx2<dimension;idx2++)
                {
                    if(idx2 == col)
                    continue;
                    subMatrix[k][l++] = matrix[idx1][idx2];
                }
                k++;
                l = 0;
            }
            inverse[row][col] = findDeterminant(dimension-1,subMatrix)*((row+col)%2==0?1:-1);
        }
    }
    transpose(dimension);
}


void evalInverse(int dimension,int determinant)
{
    for(int row = 0;row<dimension;row++)
    {
        for(int col = 0;col<dimension;col++)
        {
            inverse[row][col] = inverse[row][col]/determinant;
        }
    }
}

int main()
{
    int dimension;
    scanf("%d", &dimension);
    int matrix[dimension][dimension];
    inputMatrix(dimension,matrix);
     int determinant = findDeterminant(dimension,matrix);
    if(determinant == 0)
    {
        printf("Error cannot calculate inverse as determinant is zero\n");
        return 0;
    }
    evaluateAdjointMatrix(dimension,matrix);
   
    evalInverse(dimension,determinant);
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            printf("%d ",inverse[i][j]);
        }
        printf("\n");
    }
    return 0;
}