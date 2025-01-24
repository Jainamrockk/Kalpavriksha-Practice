#include<stdio.h>
#include<stdlib.h>


typedef struct listNode{
    int data;
    struct listNode* next;
}listNode;

int listLength(struct listNode* head)
{
    int length = 0;
    while(head)
    {
        head = head->next;
        length++;
    }
    return length;
}


struct listNode* removeNthFromEnd(struct listNode* head, int n) {
    int pos = listLength(head) - n;
    if(pos<0 || head == NULL)
    return head;
    struct listNode* node = head;
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
            head = (listNode*)malloc(sizeof(listNode*));
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            listNode* node = (listNode*)malloc(sizeof(listNode*));
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

void printLinkedList(listNode* head)
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
    listNode* head = createList();
    int n;
    printf("Enter the position from back to remove: ");
    scanf("%d",&n);
    head  = removeNthFromEnd(head,n);
    printLinkedList(head);

    return 0;
}