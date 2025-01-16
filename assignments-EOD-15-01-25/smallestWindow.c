#include<stdio.h>
#include<stdlib.h>
char* string;
char* pat;
int stringLength(char* word)
{
    int length = 0;
    while(*word!='\0')
    {
        length++;
        word++;
    }
    return length;
}
void printAns(char* left,char* right)
{
    while(left<=right)
    {
        printf("%c",*left);
        left++;
    }
}

int isAvailable(int index,int window)
{
    char* ptr = string+index;
    char* patPtr = pat;
    int checkList[256] = {0};
     while(*patPtr!='\0')
    {
        checkList[*patPtr]++;
        patPtr++;
    }
    
    while(ptr<(string+index+window))
    {
        if(checkList[*ptr]>0)
        checkList[*ptr]--;
        ptr++;
    }
    for(int index=0;index<256;index++)
    {
        if(checkList[index]>0)
       {
        return 0;
       }
    }
    ptr = string+index;
    while(ptr<(string+index+window))
    {
        printf("%c",*ptr);
        ptr++;
    }
    return 1;
}
void findSubstring()
{
    
    int lenPat = stringLength(pat);
    int lenString = stringLength(string);
    for(int window = lenPat;window<=lenString;window++)
    {
        // printf("%d ",window);
        for(int index = 0;index<=(lenString-window);index++)
        {
            // printf("%d ",index);
            if(isAvailable(index,window) == 1)
            {
                return;
            }
        }
    }
    printf("Not possible\n");

}

int main()
{
    string = (char*)malloc(100*sizeof(char));
    pat = (char*)malloc(100*sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]",string);
    getchar();
    printf("Enter Pattern:");
    scanf("%[^\n]",pat);
    getchar();
    findSubstring();

    return 0;
}
