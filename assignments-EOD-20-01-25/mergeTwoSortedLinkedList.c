
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;


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

    ListNode* head1;
    ListNode* head2;
    ListNode* tail1;
    ListNode* tail2;
 
 ListNode* mergeSorted(ListNode* head1, ListNode* head2)
 {
    
    ListNode* ptr = head1;
    ListNode* curr = head1;
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
 
ListNode* mergeLists(ListNode* head1, ListNode* head2) {

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
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
int main()
{
   printf("Enter the linked list 1: ");
   ListNode* head1 = createList();
   
   printf("\nEnter the linked list 2: ");
   ListNode* head2 = createList();

   printf("\nMerged Linked List:");
   head1 = mergeLists(head1,head2);
   printLinkedList(head1);
    return 0;
}

