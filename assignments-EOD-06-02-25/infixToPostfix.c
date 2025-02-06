#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    char* arr;
    int top;
    int capacity;
} stack;

int strLength(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        str++;
        length++;
    }
    return length;
}

void pop(stack** st)
{
    if((*st)->top == -1)
    {
        return;
    }
    (*st)->top--;
}

void push(stack** st,char ch)
{
    if((*st)->top == (*st)->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    (*st)->arr[++(*st)->top] = ch;
}


int precedence(char ch)
{
    if(ch == '^') return 3;
    if(ch == '/' || ch == '*') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

int isEmpty(stack* st)
{
    return (st->top == -1);
}

void infixToPostfix(char* input,int len)
{
    stack* st = (stack*)malloc(sizeof(stack));
    st->arr = (char*)malloc(sizeof(char)*(len+1));
    st->top = -1;
    st->capacity = len+1;
    int index = 0;
    while(len)
    {
        char ch = input[index++];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            printf("%c",ch);
        }
        else if(ch == '*' || ch == '+' || ch == '-' || ch == '/'||ch=='^')
        {
            while(isEmpty(st)!=1 && precedence(ch)<=precedence(st->arr[st->top]))
            {
                printf("%c",st->arr[st->top]);
                pop(&st);
            }
            push(&st,ch);
        }
        else if(ch == '(')
        {
            push(&st,ch);
        }
        else if(ch == ')')
        {
            while(isEmpty(st)!=1 && st->arr[st->top]!='(')
            {
                printf("%c",st->arr[st->top]);
                pop(&st);
            }
            if(isEmpty(st) == 1)
            {
                printf("Invalid Expression\n");
            }
            else
            pop(&st);
        }
        len--;
    }
    while(isEmpty(st)!=1)
    {
        printf("%c",st->arr[st->top]);
        pop(&st);
    }

}

int main()
{
    char *input = (char *)malloc(sizeof(char) * 1000);
    scanf("%[^\n]%*c", input);
    int stringLen = strLength(input);
    input = (char *)realloc(input, sizeof(char) * stringLen);
    infixToPostfix(input,stringLen);
    return 0;
}