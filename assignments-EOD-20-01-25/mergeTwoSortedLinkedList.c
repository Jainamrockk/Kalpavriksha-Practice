
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int data;
    struct listNode* next;
}listNode;


// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     ListNode* next;
 * };
 *
 */

    listNode* head1;
    listNode* head2;
    listNode* tail1;
    listNode* tail2;
 
 listNode* mergeSorted(listNode* head1, listNode* head2)
 {
    
    listNode* ptr = head1;
    listNode* curr = head1;
    head1 = head1->next;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            ptr->next = head1;
            head1 = head1->next;
            ptr = ptr->next;
            ptr ->next = NULL;
        }
        else
        {
            ptr->next = head2;
            head2 = head2->next;
            ptr = ptr->next;
            ptr ->next = NULL;   
        }
    }
    if(head1!=NULL)
    {
        ptr->next = head1;
    }
    if(head2!=NULL)
    {
        ptr->next = head2;
    }
    return curr;
 }
 
listNode* mergeLists(listNode* head1, listNode* head2) {

    if(head1 == NULL)
    return head2;
    if(head2 == NULL)
    return head1;
    
    if(head1->data<head2->data)
    {
        return mergeSorted(head1,head2);
    }
    return mergeSorted(head2,head1);

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
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
int main()
{
   printf("Enter the linked list 1: ");
   listNode* head1 = createList();
   
   printf("\nEnter the linked list 2: ");
   listNode* head2 = createList();

   printf("\nMerged Linked List:");
   head1 = mergeLists(head1,head2);
   printLinkedList(head1);
    return 0;
}

