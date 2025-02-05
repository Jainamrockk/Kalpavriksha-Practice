#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char **generate;
int numLength;

char *stringCopy(char *str1)
{
    char *input = (char *)malloc(sizeof(char) * (numLength + 1));
    char *inpPtr = input;
    while (*str1 != '\0')
    {
        *inpPtr = *str1;
        str1++;
        inpPtr++;
    }
    *inpPtr = '\0';
    return input;
}

void applyOperation(char **str)
{
    // printf("Hello\n");
    char carry = '1';
    int index = numLength - 1;
    while (carry != '0' && index >= 0)
    {
        if ((*str)[index] == '0' && carry == '1')
        {
            (*str)[index] = '1';
            carry = '0';
        }
        else if ((*str)[index] == '1' && carry == '1')
        {
            (*str)[index] = '0';
            carry = '1';
        }
        index--;
    }
    (*str)[numLength] = '\0';
}

void printBinary(char **generate, int number)
{
    for (int index = 0; index < number; index++)
    {
        printf("%s ", generate[index]);
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    generate = (char **)malloc(sizeof(char *) * number);
    numLength = floor(log(number) / log(2)) + 1;
    char *testString = (char *)malloc(sizeof(char) * (numLength + 1));
    for (int index = 0; index < numLength; index++)
    {
        testString[index] = '0';
    }

    testString[numLength] = '\0';

    for (int index = 1; index <= number; index++)
    {
        generate[index - 1] = stringCopy(testString);
        applyOperation(&generate[index - 1]);
        testString = generate[index - 1];
    }

    printBinary(generate, number);

    return 0;
}