#include<stdio.h>
#include<stdlib.h>

char* string;
int maxLen = 0;
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

void longestPalindrome(char* odd,int index1,int index2,int len)
{
    char* left = string+index1;
    char* right = string+index2;

    while(left>=string && right<string+len && *left == *right)
    {
        left--;
        right++;
    }
    left++;
char* ptr = odd;
    while(left<right)
    {
        *ptr = *left;
        ptr++;
        left++;
    }
    *ptr = '\0';
}
int main()
{
    string = (char*)malloc(100*sizeof(char));
    printf("Enter String: ");
    scanf("%[^\n]",string);
    getchar();
    int len = stringLength(string);
    maxLen = 0;
    char* ans = (char*)malloc((len+1)*sizeof(char));
    for(int index = 0;index<len;index++)
    {
        char* odd = (char*)malloc((len+1)*sizeof(char));
        char* even = (char*)malloc((len+1)*sizeof(char));
        longestPalindrome(odd,index,index,len);
        longestPalindrome(even,index,index+1,len);
        if(stringLength(odd)>maxLen)
        {
            maxLen = stringLength(odd);
            ans = odd;
        }
        if(stringLength(even)>maxLen)
        {
            maxLen  = stringLength(even);
            ans = even;
        }

    }
    printf("Longest Palindromic Substring: ");
    printf("%s",ans);
    
    return 0;
}