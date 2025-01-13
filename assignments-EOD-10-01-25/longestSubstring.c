#include<stdio.h>
#include<stdlib.h>

char* input;

int isNum(char ch)
{
    return (ch>='0' && ch<='9');
}
int isAlpha(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

void inputString()
{
    input = (char*)malloc(1000*sizeof(char));
    printf("Input a string:");
    scanf("%s",input);
}

int strLen(char* word)
{
    int length = 0;
    while(*word!='\0') {
        length++;
        word++;
        }
    return length;
}
int countLength(char* string)
{
     int alphabet[26] = {0};
        int number[10] = {0};
        int len = 0;
        while(*string!='\0')
        {
            char ch = *string;
            if(isAlpha(*string))
            {
                if(ch>='a' && ch<='z' && alphabet[ch-'a'] == 0)
                {
                    alphabet[ch-'a'] = 1;
                }
                else if(ch>='A' && ch<='Z' && alphabet[ch-'A'] == 0)
                {
                    alphabet[ch-'A'] = 1;
                }
                else
                break;
                
            }
            else if(isNum(ch))
            {
                if(number[ch-'0'] == 0)
                {
                    number[ch-'0'] = 1;
                }
                else
                break;
            }
            len++;
            string++;
        }
        return len;
}

void findLongestLengthSubstring()
{
    int size = strLen(input);
    int maxLen = 0;
    char* string = input;
    while(*string!='\0'){
        int len = countLength(string);
       if(maxLen<len)
       {
        maxLen = len;
       }
       string++;
    }
    printf("Length of the longest substring without repeating characters: %d",maxLen);
}

void solution()
{
    inputString();
    findLongestLengthSubstring();
}

int main()
{
    solution();
    return 0;
}