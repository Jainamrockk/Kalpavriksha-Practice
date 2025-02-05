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
    int c = 0;
    while(1)
    {
        int value;
        scanf("%d",&value);
        arr[c] = value;
        c++;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }


    st->capacity = c;


    arr = (int*)realloc(arr,sizeof(int)*c);
   
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
    st->size++;
}

void pop()
{
    if(isEmpty(st) == 1)
    {
        return;
    }
    --st->top;
    st->size--;
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

void printArr(int* arr,int size)
{
    for(int index =0;index<size;index++)
    {
        printf("%d ",arr[index]);
    }
    printf("\n");
}


int* nextSmallerElement(int* input)
{
    int* ans = (int*)malloc(sizeof(int)*st->capacity);
    st->arr = (int*)malloc(sizeof(int)*st->capacity);
    for(int index=0;index<st->capacity;index++)
    {
        while(isEmpty(st) != 1 && input[index]<input[st->arr[st->top]])
        {
            pop();
        }
        if(isEmpty(st) == 1)
        {
            ans[index] = -1;
        }
        else
        {
            ans[index] = input[st->arr[st->top]];
        }
        push(index);

    }
    return ans;
}


int main()
{
    st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->size = 0;
    int* arr = createArray();
    int* ans = nextSmallerElement(arr);
    printArr(ans,st->capacity);
    free(ans);
    free(arr);
    return 0;
}