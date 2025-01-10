#include <stdio.h>
#include <stdlib.h>

char *input;
int stringLen;
void swap(char *char1, char *char2)
{
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

int strLen(char *string)
{
    int length = 0;
    while (string[length] != '\0')
        length++;
    return length;
}

void inputString()
{
    input = (char *)malloc(1000 * sizeof(char));
    scanf("%s", input);
    stringLen = strLen(input);
}

void printPermutation(char *input, int index)
{
    if (index == stringLen)
    {
        printf("%s ", input);
        return;
    }
    for (int nextIndex = index; nextIndex < stringLen; nextIndex++)
    {
        if (nextIndex > index && input[nextIndex] == input[index])
            continue;
        swap(&input[index], &input[nextIndex]);
        printPermutation(input, index + 1);
        swap(&input[index], &input[nextIndex]);
    }
}

void merge(char *arr, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    char arr1[size1], arr2[size2];
    int pivotIndex = left;
    for (int index = 0; index < size1; index++)
    {
        arr1[index] = arr[pivotIndex++];
    }
    for (int index2 = 0; index2 < size2; index2++)
    {
        arr2[index2] = arr[pivotIndex++];
    }
    int index1 = 0, index2 = 0;
    pivotIndex = left;
    while (index1 < size1 && index2 < size2)
    {
        if (arr1[index1] < arr2[index2])
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
    while (index1 < size1)
    {
        arr[pivotIndex++] = arr1[index1];
        index1++;
    }
    while (index2 < size2)
    {
        arr[pivotIndex++] = arr2[index2];
        index2++;
    }
}

void mergeSort(char *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (right - left) / 2 + left;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void solution()
{
    inputString();
    mergeSort(input,0,stringLen-1);
    printPermutation(input, 0);
}

int main()
{
    solution();
    return 0;
}