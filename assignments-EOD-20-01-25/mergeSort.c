#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode{

    int data;
    struct ListNode* next;
}ListNode;

ListNode* createList()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(1)
    {
        int value;
        scanf("%d",&value);

        if(head == NULL)
        {
            head = (ListNode*)malloc(sizeof(ListNode*));
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            ListNode* node = (ListNode*)malloc(sizeof(ListNode*));
            node->data = value;
            tail->next = node;
            tail = tail->next;
            tail->next = NULL;
        }

        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    return head;
}

void printLinkedList(ListNode* head)
{
    if(head == NULL)
    {
        printf("Empty");
    }
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
   
}

ListNode* merge(ListNode* left , ListNode* mid)
{
    if(left == NULL || left->next == NULL)
    return left;
    ListNode* nn = left;
    while(nn!=mid)
    {
        nn = nn->next;
    }
    mid = mid->next;
    nn->next = NULL;
    nn = left;
    while(left!=NULL && mid!=NULL)
    {
        if(left->data<=mid->data)
        {
            left = left->next;
        }
        else
        {
            ListNode* temp = mid;
            mid = mid->next;
            left->next = temp;
            left = left->next;
            left->next = NULL;
        }
    }
    
    left->next = mid;

    return nn;
}

ListNode* calcMid(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeSort(ListNode* left)
{
    if(left == NULL)
    return NULL;
    ListNode* mid = calcMid(left);
    left =  mergeSort(left);
    mid->next = mergeSort(mid->next);
    left = merge(left,mid);
    return left;
}



int main()
{
    printf("Enter the linked list: ");
    ListNode* head = createList();
    head = mergeSort(head);
    printLinkedList(head);
    return 0;
}

