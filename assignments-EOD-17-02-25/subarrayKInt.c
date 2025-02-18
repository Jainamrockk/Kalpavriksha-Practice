#include<stdio.h>
#include<stdlib.h>


typedef struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
}hashNode;

int size,mpSize;

hashNode** hashMap;

int* getInput()
{
    int* arr = (int*)malloc(sizeof(int)*1000);

    while(1)
    {
        scanf("%d",&arr[size]);
        size++;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }  
    return arr; 
}

int hash(int key)
{
    return (size+key%size)%size;
}
void printHash()
{
    for(int index = 0;index<size;index++)
    {
        hashNode* temp = hashMap[index];
        while(temp!=NULL)
        {
            printf("%d %d\n",temp->key,temp->value);
            temp = temp->next;
        }
    }
}

hashNode* search(int key)
{
    int index = hash(key);
    hashNode* temp = hashMap[index];
    while(temp!=NULL)
    {
        if(temp->key == key)
        return temp;
        temp = temp->next;
    }
    return NULL;
}


void insert(int key)
{
    int index = hash(key);
    hashNode* temp = hashMap[index];
    while(temp!=NULL)
    {
        if(temp->key == key)
        {
            if(temp->value == 0)
            mpSize++;
            temp->value++;
            return;
        }
        temp = temp->next;
    }
    hashNode* node = (hashNode*)malloc(sizeof(hashNode));
    node->key = key;
    node->value = 1;
    node->next = hashMap[index];
    hashMap[index] = node;
    mpSize++;
   
}




int findSubarrayWithKInt(int* arr,int distinctInt)
{
    mpSize = 0;
    int count = 0;
    int left = 0,right = 0;

    while(right<size)
    {
        insert(arr[right]);
        while(left<=right && mpSize > distinctInt)
        {
            hashNode* temp = search(arr[left++]);
            temp->value--;
            if(temp->value == 0)
            mpSize--;
        }
        count += (right - left + 1);
        right++;
    }

    return count;
}

int main()
{

    int distinctInt;
    int* arr = getInput();
    hashMap = (hashNode**)calloc(sizeof(hashNode*),size);
    scanf("%d",&distinctInt);
    int count = findSubarrayWithKInt(arr,distinctInt);
    free(hashMap);
    hashMap = (hashNode**)calloc(sizeof(hashNode*),size);
    count -= findSubarrayWithKInt(arr,distinctInt-1);

    printf("%d\n",count);
    return 0;
}