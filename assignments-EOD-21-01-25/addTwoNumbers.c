#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
    int val;
    struct listNode* next;
}listNode;


struct listNode* addTwoNumbers(struct listNode* l1, struct listNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct listNode* node =  (struct listNode*)malloc(sizeof(struct listNode));
    int sum = l1->val+l2->val,carry = 0;
    node->val = sum%10;
    node->next = NULL;
    carry = sum/10;
    struct listNode* temp = node;
    l1 = l1->next;
    l2 = l2->next;
   while(l1!=NULL && l2!=NULL)
   {
    struct listNode* nn =  (struct listNode*)malloc(sizeof(struct listNode));
    sum = l1->val + l2->val + carry;
    nn->val = sum%10;
    nn->next = NULL;
    carry = sum/10;
    temp->next = nn;
    temp = nn;
    l1 = l1->next;
    l2 = l2->next;
   }
 

 if(l1!=NULL)
{
    temp->next = l1;
    temp = temp->next;
    while(carry && temp!=NULL)
    {
        int sum = (temp->val+carry);
        carry = sum/10;
        temp->val = sum%10;
        if(temp->next == NULL)
        break;
        temp = temp->next;
    }
}

 if(l2!=NULL)
{
    temp->next = l2;
    temp = temp->next;
    while(carry && temp!=NULL)
    {
        int sum = (temp->val+carry);
        carry = sum/10;
        temp->val = sum%10;
        if(temp->next == NULL)
        break;
        temp = temp->next;
    }
}

while(carry>0)
{
    struct listNode* nn =  (struct listNode*)malloc(sizeof(struct listNode));
    nn->val = carry%10;
    nn->next = NULL;
    carry = carry/10;
    temp->next = nn;
    temp = nn;
}


   return node;
}


listNode* createLinkedList()
{
    int value;
    scanf("%d",&value);
    struct listNode* head =  (struct listNode*)malloc(sizeof(struct listNode));
    head->val = value%10;
    value = value/10;
    head->next = NULL;
    listNode* temp = head;
    while(value)
    {
        struct listNode* nn =  (struct listNode*)malloc(sizeof(struct listNode));
        nn->val = value%10;
        nn->next;
        temp->next = nn;
        temp = nn;
        value  = value/10;

    }
    temp->next = NULL;
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

int main()
{
    printf("Enter the number 1:");
    listNode* head1 = createLinkedList();
    printf("Enter the number 2: ");
    listNode* head2 = createLinkedList();
    head1 = addTwoNumbers(head1,head2);
    printf("Sum is:");
    printLinkedList(head1);
    return 0;
}