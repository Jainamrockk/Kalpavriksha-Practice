#include <stdio.h>
#include <stdlib.h>

char *input;
int alphabets[26] = {0};
int numbers[10]= {0};
void inputString()
{
    input = (char *)malloc(1000 * sizeof(char));
    scanf("%s", input);
}

int strLen()
{
    int length = 0;
    while (input[length] != '\0')
        length++;
    return length;
}

void removeDuplicates()
{
    int index = 0, alphabetIndex = 0;
    while (input[index] != '\0')
    {
        char ch = input[index];
        if (ch >= 'a' && ch <= 'z')
        {
            if (alphabets[ch - 'a'] == 0)
            {
                input[alphabetIndex++] = ch;
                alphabets[ch - 'a']++;
            }
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            if (alphabets[ch - 'A'] == 0)
            {
                input[alphabetIndex++] = ch;
                alphabets[ch - 'a']++;
                
            }
        }
        else if(ch>='0' && ch<='9')
        {
            if (numbers[ch - '0'] == 0)
            {
                input[alphabetIndex++] = ch;
                numbers[ch - '0']++;
            }
        }
        index++;
    }
    
    input = (char*)realloc(input,(alphabetIndex-2)*sizeof(char));
    input[alphabetIndex] = '\0';
    printf("%s",input);
    
}

void solution()
{
    inputString();
    removeDuplicates();
}

int main()
{
    solution();
    return 0;
}