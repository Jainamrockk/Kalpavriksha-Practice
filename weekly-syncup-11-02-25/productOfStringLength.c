#include<stdio.h>
#include<stdlib.h>


char** stringArray;
int size;

int stringLength(char* str)
{
    int length = 0;
    while(*str!='\0')
    {
        length++;
        str++;
    }
    return length;
}

void getInput()
{
    int index = 0;
    while(1)
    {
        char* string = (char*)malloc(sizeof(char)*100);
        scanf("%s",string);
        stringArray[index++] = string;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    size = index;
    stringArray = (char**)realloc(stringArray,sizeof(char*)*size);
}

int stringCmp(char* str1,char* str2)
{
    while(*str1!='\0')
    {
        char* temp = str2;
        while(*temp!='\0')
        {
            if(*temp == *str1)
            {
                return 0;
            }
            temp++;
        }
        str1++;
    }
    return 1;
}

void findProduct()
{
    int maxProduct = 0;
    for(int index = 0;index<size-1;index++)
    {
        for(int index2 = index+1;index2<size;index2++)
        {
            int check = stringCmp(stringArray[index],stringArray[index2]);
            if(check == 1)
            {
                int len = stringLength(stringArray[index])*stringLength(stringArray[index2]);
                maxProduct = (maxProduct<len)?len:maxProduct;
            }
        }
    }
    printf("Max Product:%d\n",maxProduct);
}



int main()
{
    stringArray = (char**)malloc(sizeof(char*)*100);
    size = 100;
    getInput();
    findProduct();
    return 0;
}