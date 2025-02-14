#include <stdio.h>
#include <stdlib.h>

typedef struct hashNode
{
    int key;
    int value;
    struct hashNode* next;

}hashNode;

int size;
hashNode** hashMap;


int hash(int key)
{
    // printf("---- %d\n",key%size);
    return abs(key%size);
}


void insert(int key,int val)
{
    int index = hash(key);
    hashNode* temp = hashMap[index];
  
    while(temp!=NULL)
    {
        if(temp->key == key)
        return;
        temp = temp->next;
    }
    hashNode* node = (hashNode*)malloc(sizeof(hashNode));
    node->key = key;
    node->value = val;
    node->next = hashMap[index];
    hashMap[index] = node;

}

hashNode* search(int key)
{
    int index = hash(key);
    if(hashMap[index] == NULL)
    return NULL;
    hashNode* temp = hashMap[index];
    while(temp!=NULL)
    {
        if(temp->key == key)
        return temp;
        temp = temp->next;
    }
    return NULL;
}

int *getInput()
{
    int *arr = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    while (1)
    {
        scanf("%d", &arr[index++]);
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }
    size = index;
    return arr;
}

int main()
{
    hashMap = (hashNode**)malloc(sizeof(hashNode*)*(100001));
  
    int *arr = getInput();
    for(int index = 0;index<=100000;index++)
    {
        hashMap[index] = NULL;
    }
    int maxSubLength = -1;
    int count = 0;
    for(int index=0;index<size;index++)
    {
        count += (arr[index] == 0)?-1:1;
        if(count == 0)
        {
            maxSubLength = index+1;
            continue;
        }
        hashNode* temp = search(count);
        // printf("%d",count);
        if(temp!=NULL)
        {
            maxSubLength = maxSubLength>(index - temp->value)?maxSubLength:(index-temp->value);
        }
        else
        {
            insert(count,index);
        }
    }
    printf("%d\n",maxSubLength);
    return 0;
}