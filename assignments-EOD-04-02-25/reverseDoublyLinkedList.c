#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode* next;
    struct listNode* prev;
}listNode;

listNode* createList()
{
    listNode* head = NULL;
    listNode* tail = NULL;

    while(1)
    {
        int value;
        scanf("%d",&value);
        listNode* node = (listNode*)malloc(sizeof(listNode));
        node->next = NULL;
        node->prev = NULL;
        node->val = value;
        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    return head;
}

void printList(listNode* head)
{
    listNode* temp = head;
    while(temp)
    {
        printf("%d ",temp->val);
        if(temp->next)
        {
            printf("-> ");
        }
        temp =temp->next;
    }
}

void reverseList(listNode** head)
{
    listNode* temp = *head;
    while(temp)
    {
        listNode* next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        *head = temp;
        temp = temp->prev;
    }

}

int main()
{
    listNode* head = createList();
    reverseList(&head);
    printList(head);
    return 0;
}