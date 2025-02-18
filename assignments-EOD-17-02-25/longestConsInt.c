#include<stdio.h>
#include<stdlib.h>

typedef struct hashNode
{
    int key;
    int value;
    struct hashNode* next;
}hashNode;

hashNode** hashMap;
int size,minElement,maxElement,mpSize;

int hash(int key)
{
    return (size+key%size)%size;
}

int* getInput()
{
    int* arr = (int*)malloc(sizeof(int)*100);
    while(1)
    {
        scanf("%d",&arr[size++]);
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    return arr;
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
    if(temp == NULL)
    {
        mpSize++;
    }
    while(temp!=NULL)
    {
        if(temp->key == key)
        return;
        temp = temp->next;
    }
    minElement = minElement>key?key:minElement;
    maxElement = maxElement>key?maxElement:key;
    hashNode* node = (hashNode*)malloc(sizeof(hashNode));
    node->key = key;
    node->value = 1;
    node->next = hashMap[index];
    hashMap[index] = node;
}

void insertIntoMap(int* arr)
{
    for(int index=0;index<size;index++)
    {
        insert(arr[index]);
    }
}

int findLongestConsecutiveInt()
{
    int maxCount = 0;
    int count = 0;

    for(int index = minElement;index<=maxElement;index++)
    {
        if(search(index)!=NULL)
        count++;
        else
        {
            maxCount = maxCount<count?count:maxCount;
            count = 0;
        }
    }
    maxCount = maxCount<count?count:maxCount;
    return maxCount;
}

// void printMap()
// {
//     for(int index=0;index<mpSize;index++)
//     {
//         hashNode* temp = hashMap[index];
//         printf("...\n");
//         while(temp!=NULL)
//         {
//             printf("%d -> %d\n",temp->key,temp->value);
//             temp = temp->next;
//         }
//     }
// }

int main()
{
    int* arr = getInput();
    hashMap = (hashNode**)calloc(sizeof(hashNode*),1000);
    insertIntoMap(arr);
    // printMap();
    int longest = findLongestConsecutiveInt();
    printf("%d\n",longest);
    return 0;
}