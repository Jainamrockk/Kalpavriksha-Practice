#include <stdio.h>
#include <stdlib.h>

int *desiredApartments, *apartmentSize;


void merge(int *arr, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    int pivotIndex = left;
    for (int index = 0; index < size1; index++)
    {
        arr1[index] = arr[pivotIndex++];
    }
    for (int index = 0; index < size2; index++)
    {
        arr2[index] = arr[pivotIndex++];
    }

    int index1 = 0, index2 = 0;
    pivotIndex = left;
    while (index1 < size1 && index2 < size2)
    {
        if (arr1[index1] <= arr2[index2])
        {
            arr[pivotIndex++] = arr1[index1++];
        }
        else
        {
            arr[pivotIndex++] = arr2[index2++];
        }
    }
    while (index1 < size1)
    {
        arr[pivotIndex++] = arr1[index1++];
    }
    while (index2 < size2)
    {
        arr[pivotIndex++] = arr2[index2++];
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (right - left) / 2 + left;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int searchApartment(int apartmentsSize,int applicantsSize,int maxDifference)
{
    int index1 = 0,index2 = 0,count = 0;
    while(index1<apartmentsSize && index2<applicantsSize)
    {
        if(abs(apartmentSize[index1] - desiredApartments[index2])<=maxDifference)
        {
            count++;
            index1++;
            index2++;
        }
        else if(apartmentSize[index1] > desiredApartments[index2])
        index2++;
        else
        index1++;
    }
    return count;
}

void printArr(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int applicantsSize, apartmentsSize, maxDifference;
    scanf("%d%d%d", &applicantsSize, &apartmentsSize, &maxDifference);
    desiredApartments = (int *)malloc(applicantsSize*sizeof(int));
    apartmentSize = (int *)malloc(apartmentsSize*sizeof(int));
    for (int index = 0; index < applicantsSize; index++)
    {
        scanf("%d", &desiredApartments[index]);
    }
    for (int index = 0; index < apartmentsSize; index++)
    {
        scanf("%d", &apartmentSize[index]);
    }
    mergeSort(apartmentSize, 0, apartmentsSize-1);
    mergeSort(desiredApartments, 0, applicantsSize-1);
    // printArr(apartmentSize,apartmentsSize);

    int count = 0;  
    count = searchApartment(apartmentsSize,applicantsSize,maxDifference);   
    printf("%d", count);
    return 0;
}