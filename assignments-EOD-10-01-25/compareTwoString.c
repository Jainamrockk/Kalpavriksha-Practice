#include<stdio.h>
#include<stdlib.h>
   char* word1;
    char* word2;
int strCmp(char* word1,char* word2)
{
    while(*word1!='\0' && *word2!='\0')
    {
        if(*word1!=*word2)
        return *word1-*word2;
        word1++;
        word2++;
    }
    return *word1-*word2;
}

void inputWords()
{
    printf("Enter String 1:");
    word1 = (char*)malloc(1000*sizeof(char));
    *word1 = '\0';
    scanf("%[^\n]",word1);
    getchar();
    printf("Enter String 2:");
    word2 = (char*)malloc(1000*sizeof(char));
    *word2 = '\0';
    scanf("%[^\n]",word2);
    getchar();
}
void compareWords()
{
    if(strCmp(word1,word2) == 0)
    {
        printf("Both Words are same");
        return;
    }
        printf("Both Words are not same");
}
void solution()
{
    inputWords();
    compareWords();
}
int main()
{
    solution();
    return 0;
}