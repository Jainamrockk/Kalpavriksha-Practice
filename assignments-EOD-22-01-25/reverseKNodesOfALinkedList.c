#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
} listNode;

listNode *createList()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (1)
    {
        int value;
        if(scanf("%d", &value) == 0)
        {
            printf("Enter only integers.\n");
            getchar();
            return head;
        }
        if (head == NULL)
        {
            head = (listNode *)malloc(sizeof(listNode));
            head->val = value;
            head->next = NULL;
            tail = head;
            continue;
        }
        listNode *node = (listNode *)malloc(sizeof(listNode));
        node->val = value;
        node->next = NULL;
        tail->next = node;
        tail = node;
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }
    return head;
}
int listLength(listNode* head)
{
    int length = 0;
    while(head)
    {
        head = head->next;
        length++;
    }
    return length;
}
listNode* reverseNodes(listNode* head,int length,int k)
{
    if(!head || length == 0)
    return head;

    int count = k;
    listNode* prev = NULL;
    listNode* fwd = NULL;
    listNode* curr = head;
    while(count)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count--;
    }
    head->next = reverseNodes(curr,length-k,k);
    return prev;
}
listNode* reverseKNodes(listNode* head,int k)
{
    if(!head && !head->next)
    return head;

    int length = listLength(head);
    length -= length%k;
    if(length<0)
    return head;
    head =  reverseNodes(head,length,k);
    return head;
}

void printLL(listNode* head)
{
    while(head)
    {
        printf("%d",head->val);
        head = head->next;
        if(head)
        {
            printf("->");
        }
    }
}

int main()
{
    int shift;
    printf("Enter the linked list: ");
    listNode* head = createList();
    printf("Enter the shift nodes:");
    scanf("%d",&shift);
    if(shift<0)
    {
        printf("Invalid shift value");
        return 0;
    }
    printf("\nLinked List before reversing every K nodes: ");
    printLL(head);
    printf("\nLinked List after reversing every K nodes: ");
    head = reverseKNodes(head,shift);
    printLL(head);
    return 0;
}