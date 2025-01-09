#include<stdio.h>
#include<stdlib.h>
char* input;


void inputString()
{
    input = (char*)malloc(1000*sizeof(char));
    scanf("%s",input);
}
int strLen(char* string)
{
    int length = 0;
    while(string[length]!='\0') length++;
    return length;
}
void isPalindrome()
{
    int right = strLen(input)-1;
    int left = 0;
    while(left<right)
    {
        if(input[left]!=input[right]){
            printf("%s is not a Palindrome",input);
            return;
        }
        left++;
        right--;
    } 
    printf("%s is a Palindrome",input);
}

void solution()
{
    inputString();
    isPalindrome();
}
int main()
{
    solution();
    return 0;
}