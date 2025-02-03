#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
} listNode;


int listLength(listNode* head)
{
    int length = 0;
    while(head)
    {
        length++;
        head = head->next;
    }
    return length;
}


listNode* createList()
{
    listNode* head = NULL;
    listNode* tail = NULL;
    while(1)
    {
        int value;
        scanf("%d",&value);
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
        printf("%d",head->val);
        if(head->next!=NULL)
        printf("-> ");
        head = head->next;
    }
}

listNode* findMid(listNode* left)
{
    if(!left || !left->next)
    return left;
    listNode* slow = left;
    listNode* fast = left;
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


listNode* merge(listNode* left,listNode* right)
{
    if(!left) return right;
    if(!right) return left;
    if(left->val<right->val)
    {
        left->next = merge(left->next,right);
        return left->next;
    }
    right->next = merge(left,right->next);
    return right;
}


listNode* mergeSort(listNode* head)
{
    if(head == NULL || head->next == NULL)
    return head;

    listNode* mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid->next);
    head = merge(head,mid);
    return head;
}

listNode* applySort(listNode* head,int operationalLength,int k)
{
    listNode* temp = head;
    int flag = 0,first = 0;
    while(operationalLength>0 && temp!=NULL)
    {
        operationalLength -= k;
        int tempK = k;
        listNode* left = temp;
        while(tempK>=1)
        {
            temp = temp->next;
            tempK--;
        }
        if(!flag%2){
        listNode* right = temp->next;
        temp->next = NULL;
        left = mergeSort(left);
        if(first == 0)
        {
            head = left;
            first = 1;
        }
        temp->next = right;
    }
    flag = 1 - flag;
    }
    return head;    
}

int main()
{
    int k;
    printf("Enter the linked list: ");
    listNode* head = createList();
    printf("Enter K:");
    scanf("%d",&k);
    int Length = listLength(head);
    int operationalLength =Length - Length%k;
    head = applySort(head,operationalLength,k);
    printLinkedList(head);
    return 0;
}
