#include<stdio.h>
#include<stdlib.h>

char* input;
int Num,Alpha,special;
int isNum(char ch)
{
    return (ch>='0' && ch<='9');
}
int isAlpha(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}


void countChar()
{
    Num = 0,Alpha = 0,special = 0;
    while(*input!='\0')
    {
        char ch = *input;
        if(isAlpha(ch))
        {Alpha++;}
        else if(isNum(ch))
        {Num++;}
        else
        {
            special++;
        }
        input++;
    }
}

void inputString()
{
    printf("Enter the string:");
    input = (char*)malloc(1000*sizeof(char));
    scanf("%[^\n]%*c",input);
}

void printConstraints()
{
    printf("Number of Alphabets:%d\n",Alpha);
    printf("Number of Numbers:%d\n",Num);
    printf("Number of Special Characters:%d\n",special);
}

void solution()
{
    inputString();
    countChar();
    printConstraints();
}

int main()
{
    solution();
    return 0;
}