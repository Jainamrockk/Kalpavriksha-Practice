#include<stdio.h>
#include<stdlib.h>
int* arr;


void merge(int* arr,int left,int mid,int right)
{
    int size1 = mid-left+1;
    int size2 = right-mid;
    int arr1[size1];
    int arr2[size2];
    int pivotIndex = left;
    for(int index = 0;index<size1;index++)
    {
        arr1[index] = arr[pivotIndex++];
    }
    for(int index=0;index<size2;index++)
    {
        arr2[index] = arr[pivotIndex++];
    }
    int index1 = 0,index2 = 0;
    pivotIndex = left;
    while(index1<size1 && index2<size2)
    {
        if(arr1[index1]<arr2[index2])
        {
            arr[pivotIndex++] = arr1[index1];
            index1++;
        }
        else
        {
            arr[pivotIndex++] = arr2[index2];
            index2++;
        }
    }
    while(index1<size1)
    {
        arr[pivotIndex++] = arr1[index1];
        index1++;
    }
    while(index2<size2)
    {
        arr[pivotIndex++] = arr2[index2];
        index2++;
    }

}


void mergeSort(int* arr,int left,int right)
{
    if(left>=right)
    return;
    int mid = (right-left)/2 + left;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}



void printDistinct(int* arr,int right)
{
    int left = 0;
    int count = 1;

    while(left<(right-1))
    {
        if(arr[left]!=arr[++left])
        count++;
    }
    printf("%d",count);
}

int main()
{
    int size;
    scanf("%d",&size);
    if(size == 0)
    {
        printf("0");
        return 0;
    }
    arr = (int*)calloc(size,sizeof(int));
    for(int index=0;index<size;index++)
    {
        scanf("%d",&arr[index]);
    }
    mergeSort(arr,0,size-1);
   
    printDistinct(arr,size);
    return 0;
}