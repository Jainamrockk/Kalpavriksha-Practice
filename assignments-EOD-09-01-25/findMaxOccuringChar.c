#include<stdio.h>
#include<stdlib.h>
char* input;
int alphabets[26] = {0};
void inputString()
{
    input = (char*)malloc(1000*sizeof(char));
    scanf("%s",input);
}
int maxCount()
{
    int index = 0;

    int maxCount = 0;
    while(input[index]!='\0')
    {
        char ch = input[index];
        if(ch>='a' && ch<='z'){
        alphabets[input[index]-'a']++;
        if(maxCount< alphabets[input[index]-'a'])
        maxCount = alphabets[input[index]-'a'];
        }
        else if(ch>='A' && ch<='Z')
        {
             alphabets[input[index]-'A']++;
        if(maxCount< alphabets[input[index]-'A'])
        maxCount = alphabets[input[index]-'A'];
        }
        index++;
    }
    return maxCount;
}


void printMaxCount(int maxChar)
{
    int index = 0;
    while(index<26)
    {
        if(alphabets[index] == maxChar)
        {
            printf("%c ",('a'+index));
        }
            index++;
    }

}
void solution()
{
    inputString();
    int maxChar = maxCount();
    printMaxCount(maxChar);
}
int main()
{
    solution();
    return 0;
}