#include <stdio.h>
#include <stdlib.h>
char *string;
char *searchString;
void inputString()
{
    printf("Enter String:");
    string = (char *)malloc(1000 * sizeof(char));
    scanf("%s", string);
}
void inputSearchString()
{
    printf("Enter Search String:");
    searchString = (char *)malloc(1000 * sizeof(char));
    scanf("%s", searchString);
}
int strCmp(char *word1, char *word2)
{
    while ( *word2 != '\0')
    {
        if (*word2 != *word1)
        {
            return *word2 - *word1;
        }
        word2++;
        word1++;
    }
    return 0;
}

void isSubstringPresent()
{
    char *w1 = string;
    char *w2 = searchString;
    while (*w1 != '\0')
    {
        if (strCmp(w1, w2) == 0)
        {
            printf("Yes");
            break;
        }
        w1++;
    }
    if (*w1 == '\0')
        printf("No");
}
void solution()
{
    inputString();
    inputSearchString();
    isSubstringPresent();
}
int main()
{
    solution();
    return 0;
}