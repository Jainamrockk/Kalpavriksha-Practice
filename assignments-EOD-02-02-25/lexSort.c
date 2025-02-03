#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    char* val;
    struct listNode *next;
} listNode;

listNode* createList()
{
    listNode* head = NULL;
    listNode* tail = NULL;
    while(1)
    {
        char* value = (char*)malloc(sizeof(char)*100);
        scanf("%s",value);
        if(head == NULL)
        {
            head = (listNode*)malloc(sizeof(listNode));
            head->val = value;
            head->next = NULL;
            tail = head;
            continue;
        }
        listNode* node = (listNode*)malloc(sizeof(listNode));
        node->val = value;
        node->next = NULL;
        tail->next = node;
        tail = node;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;

    }
    return head;
}

void printLinkedList(listNode* head)
{
    while(head)
    {
        printf("%s",head->val);
        if(head->next!=NULL)
        printf(" -> ");
        head = head->next;
    }
}

listNode* findMid(listNode* head)
{
    if(!head || !head->next)
    return head;
    listNode* fast = head;
    listNode* slow = head;
    while(!fast && !fast->next)
    {
        fast = fast->next->next;
        if(!fast)
        slow = slow->next;
    }
    listNode* temp = slow->next;
    slow->next = NULL;
    return temp;

}


int strCmp(char* s1,char* s2)
{
    while(*s1!='\0' && *s2!='\0')
    {
        if(*s1!=*s2)
        return *s1-*s2;
        s1++;
        s2++;
    }
    return *s1-*s2;
}

listNode* merge(listNode* left,listNode* right)
{
    if(!left) return right;
    if(!right) return left;

    if(strCmp(left->val,right->val)<=0)
    {
        left->next = merge(left->next,right);
        return left;
    }
    right->next = merge(left,right->next);
    return right;
}

listNode* mergeSort(listNode* head)
{
    if(!head || !head->next)
    return head;
    listNode* mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head,mid);
}

int main()
{
    listNode* head = createList();
    head = mergeSort(head);
    printLinkedList(head);
    return 0;
}