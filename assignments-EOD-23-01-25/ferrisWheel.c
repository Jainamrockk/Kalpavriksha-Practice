#include <stdio.h>
#include <stdlib.h>

int *childrenWeight;

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
    free(arr1);
    free(arr2);
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

int minNumberOfGoods(int *arr, int size, int maxLimit)
{
    int left = 0, right = size - 1, count = 0;
    while (left <= right)
    {
        if (arr[left] + arr[right] <= maxLimit)
        {
            left++;
        }
        right--;
        count++;
    }
    return count;
}

int main()
{
    int numberOfChildren, maxWeight;
    scanf("%d%d", &numberOfChildren, &maxWeight);
    childrenWeight = (int *)calloc(numberOfChildren, sizeof(int));
    for (int index = 0; index < numberOfChildren; index++)
    {
        scanf("%d", &childrenWeight[index]);
    }
    mergeSort(childrenWeight, 0, numberOfChildren - 1);
    int minGoods = minNumberOfGoods(childrenWeight, numberOfChildren, maxWeight);
    printf("%d", minGoods);
    return 0;
}