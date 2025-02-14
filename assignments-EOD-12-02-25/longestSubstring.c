#include<stdio.h>
#include<stdlib.h>
char* string;
int maxSubLength;
int stringLength(char* string)
{
    int length = 0;
    while(*string!='\0')
    {
        string++;
        length++;
    }
    return length;
}
void findSubstringLength(char* str,int startIndex,int currIndex,int size,int countArr[26],int distinctElements,int maxDistinctCharacters)
{
    if(distinctElements == maxDistinctCharacters+1)
    {
        maxSubLength = maxSubLength<(currIndex - startIndex-1)?(currIndex - startIndex-1):maxSubLength;
        return;
    }
    if(currIndex == size)
    {
        if(distinctElements == maxDistinctCharacters)
    {
        maxSubLength = maxSubLength<(currIndex - startIndex)?(currIndex - startIndex):maxSubLength;
    }
        return;}

    if(countArr[str[currIndex] - 'a'] == 0)
    {
        distinctElements++;
        countArr[str[currIndex] - 'a'] = 1;
    }
    findSubstringLength(str,startIndex,currIndex+1,size,countArr,distinctElements,maxDistinctCharacters);
    int countArr2[26] = {0};
    countArr2[str[currIndex] - 'a'] = 1;
    findSubstringLength(str,currIndex,currIndex+1,size,countArr2,1,maxDistinctCharacters);
}
int main()
{
    int distinctCharacters;
    string = (char*)malloc(sizeof(char)*100);
    scanf("%[^\n]%*c",string);
    int length = stringLength(string);
    scanf("%d",&distinctCharacters);
    maxSubLength = -1;
    int countArr[26] = {0};
    findSubstringLength(string,0,0,length,countArr,0,distinctCharacters);
    printf("%d\n",maxSubLength);
    return 0;
}