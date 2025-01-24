#include<stdio.h>
#include<stdlib.h>

char* string;

void inputString()
{
    string = (char*)malloc(1000*sizeof(char));
     scanf("%[^\n]",string);
     getchar();
}

void removeDuplicates()
{
    int index = 0,flag = 0;
    int characters[500] = {0};
    while(string[index]!='\0')
    {
        char ch = string[index];
        if(characters[ch]==0)
        {
         characters[ch]=1;
         string[flag++] = ch;   
        }
        index++;
    }
    string[flag] = '\0';

}

int main()
{
    inputString();
    removeDuplicates();
    printf("%s",string);
    return 0;
}       