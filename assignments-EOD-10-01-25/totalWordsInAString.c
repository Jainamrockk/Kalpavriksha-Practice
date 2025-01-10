#include<stdio.h>
#include<stdlib.h>
int totalWords;
int isAlphaNum(char ch)
{
    return (ch>='a' && ch<='z') ||(ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
}

int countTotalWords(char* word)
{
    int count = 0,index=0,charCount=0;
    while(word[index]!='\0')
    {
        char ch = word[index];
        index++;
        if(isAlphaNum(ch)) 
        {
            charCount++;
            continue;
        }
        count+=(charCount>0);
        charCount = 0;
    }
    return count+isAlphaNum(word[index-1]);
}

void inputSentence()
{
    totalWords = 0;
  
        char* words = (char*)malloc(1000*sizeof(char));
        scanf("%[^\n]%*c",words);
        totalWords += countTotalWords(words);
    
}

void printTotalWords()
{
    printf("Total Words are:%d",totalWords);
}

void solution()
{
    inputSentence();
    printTotalWords();
}
int main()
{
    solution();
    return 0;
}