#include<stdio.h>
#include<stdlib.h>
char* sentence;

void inputString()
{
    printf("Enter the sentence:");
    sentence = (char*)malloc(1000*sizeof(char));
    scanf("%[^\n]",sentence);
    getchar();
}

void evaluateShortestAndLongestWord()
{
    int shortestLength=1e9+7,longestLength=0,length=0,smallestIndex = 0,largestIndex=0,index=0;
    char* shortest;
    char* longest;
    char* input = sentence;
    while(*input!='\0')
    {
        char ch = *input;
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            length++;
        }
        else
        {
            if(length>longestLength)
            {
                longestLength = length;
                largestIndex =  index-length;
            }
            if(length<shortestLength)
            {
                shortestLength = length;
                smallestIndex =  index-length;
            }
            length = 0;
        }
        input++;
        index++;
    }
    if(length>longestLength)
            {
                longestLength = length;
                largestIndex =  index-length;
            }
            if(length<shortestLength)
            {
                shortestLength = length;
                smallestIndex =  index-length;
            }
    input = sentence;
    index = 0;
    printf("Shortest Word: ");
    while(*input!='\0')
    {
        if(index>=smallestIndex && index<smallestIndex+shortestLength)
        printf("%c",*input);
        input++;
        index++;
    }
    printf("\n");
    input = sentence;
    index = 0;
    printf("Longest Word: ");
     while(*input!='\0')
    {
        if(index>=largestIndex && index<longestLength+largestIndex)
        printf("%c",*input);
        input++;
        index++;
    }
}

void solution()
{
    inputString();
    evaluateShortestAndLongestWord();
}

int main()
{
    solution();
    return 0;
}