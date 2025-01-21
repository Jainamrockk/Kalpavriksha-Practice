#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;

int listLength(struct ListNode* head)
{
    int length = 0;
    while(head)
    {
        head = head->next;
        length++;
    }
    return length;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int pos = listLength(head) - n;
    if(pos<0 || head == NULL)
    return head;
    struct ListNode* node = head;
    if(pos == 0)
    {
        head = head->next;
        node->next = NULL;
        free(node);
        return head;
    }
    while(pos>1)
    {
        node = node->next;
        pos--;
    }

    node->next = node->next->next;
    return head;
       
}


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
    
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
   
}


int main()
{
    printf("Enter the linked list: ");
    ListNode* head = createList();
    int n;
    printf("Enter the position from back to remove: ");
    scanf("%d",&n);
    head  = removeNthFromEnd(head,n);
    printLinkedList(head);

    return 0;
}