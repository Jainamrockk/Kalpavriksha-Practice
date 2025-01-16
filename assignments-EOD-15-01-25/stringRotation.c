#include<stdio.h>
#include<stdlib.h>

char* string1;
char* string2; 
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

void isRotation(char* string1,char* string2)
{
    int len1 = stringLength(string1);
    int len2 = stringLength(string2);
    int flag = 1;
    if(len1!=len2)
    {
        printf("Invalid\n");
        return;
    }
    for(int index1 = 0;index1<len2;index1++)
    {
        char* ptr1 = string1;
        char* ptr2 = string2+index1;
        if(*ptr1!=*ptr2)
        continue;
        int k = index1;
        flag = 1;
       while(*ptr1!='\0')
       {
        if(*ptr1!=*ptr2)
        {
            flag = 0;
            break;
        }
            k++;
            ptr2 = string2+(k%(len1));
            if(*ptr2 == '\0')
            continue;
            ptr1++;
       }
       if(flag == 1)
       {
        printf("true\n");
        return;
       }
    }
    printf("false");
}


int main()
{
    string1 = (char*)malloc(100*sizeof(char));
    string2 = (char*)malloc(100*sizeof(char));
    printf("Enter String 1:");
    scanf("%[^\n]",string1);
    getchar();
    printf("Enter String 2:");
    scanf("%[^\n]",string2);
    isRotation(string1,string2);

    return 0;
}