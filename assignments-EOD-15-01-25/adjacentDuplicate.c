#include<stdio.h>
#include<stdlib.h>
char* string;
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

void swapString(char* word)
{
    while(*(word+2)!='\0')
    {
        *word = *(word+2);
        word++;
    }
    *word = '\0';
}
void removeAdjacentDuplicates()
{
    char* word = string;
    int length = stringLength(string);
    if(length <=1)
    return;
    while(length>1){
    int flag = 0;
    word = string;
    for(int i=0;i<length-1;i++)
    {
        if(*word == *(word+1))
        {
            if(length == 2)
            {
                string = "";
                return;
            }
            swapString(word);
            flag = 1;
        }
        word++;
    }
    if(flag == 0)
    break;
    length = stringLength(string);
    }

}


int main()
{
    string = (char*)malloc(100*sizeof(char));
    printf("Enter String:");
    scanf("%[^\n]",string);
    getchar();
    removeAdjacentDuplicates();
    printf("After Removing Adjacent Duplicates: ");
    if(stringLength(string) == 0)
    {
        printf("Empty String");
    }
    else
    printf("%s",string);
    return 0;
}
