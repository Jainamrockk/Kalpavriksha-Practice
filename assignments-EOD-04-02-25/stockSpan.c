#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int* arr;
    int top;
    int capacity;
    int size;
}stack;

stack* st;

int* createArray()
{
    int* arr = (int*)malloc(sizeof(int)*1000);
    int capacity = 0;
    while(1)
    {
        int value;
        scanf("%d",&value);
        arr[capacity] = value;
        capacity++;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    arr = (int*)realloc(arr,sizeof(int)*capacity);
    st->capacity = capacity;
    return arr;
}

int isFull(stack* st)
{
    return (st->top == st->capacity-1);
}

int isEmpty(stack* st)
{
    return (st->top == -1);
}

void push(int value)
{
    if(isFull(st))
    {
        st->capacity*=2;
        st->arr = (int*)realloc(st->arr,sizeof(int)*st->capacity);
    }
    st->arr[++st->top] = value;
}

void pop()
{
    if(isEmpty(st) == 1)
    {
        printf("Hell\n");
        return;
    }
    --st->top;
}

void printStack(stack* st)
{
    if(isEmpty(st)==1)
    {
        return;
    }   
    printf("%d ",st->top);
    int val = st->top;
    pop();
    printStack(st);
    push(val);
}

int* stockSpan(int* input)
{
    int* ans = (int*)malloc(sizeof(int)*st->capacity);
    for(int index=0;index<st->capacity;index++)
    {
        while(!isEmpty(st) && input[index]>=input[st->arr[st->top]])
        {
            pop();
        }
        if(isEmpty(st) == 1)
        {
            ans[index] = index+1;
        }
        else
        {
            ans[index] = index - st->arr[st->top];
        }
        push(index);
    }
    return ans;
}

void printArr(int* arr,int size)
{
    for(int index =0;index<size;index++)
    {
        printf("%d ",arr[index]);
    }
    printf("\n");
}

int main()
{
    st = (stack*)malloc(sizeof(stack));
    st->size = 0;
    st->top = -1;
    int* input = createArray();
    st->arr = (int*)malloc(sizeof(int)*st->capacity);
    int* ans = stockSpan(input);
    printArr(ans,st->capacity);
    return 0;
}