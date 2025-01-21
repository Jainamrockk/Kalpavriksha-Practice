#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
} listNode;



listNode* oddEvenList(listNode* head)
{
    if(head == NULL || head->next == NULL)
    return head;
    listNode *even = NULL,*n1 = NULL;
    listNode *odd = NULL, *n2 = NULL;
    while(head!=NULL)
    {
        if((head->val)%2 == 0)
        {
            if(even == NULL)
            {
                even = head;
                n1 = even;
                head = head->next;
            }
            else{
            even->next = head;
            even = head;
            head = head->next;
            even->next = NULL;
            }

        }
        else
        {
            if(odd == NULL)
            {
                odd = head;
                n2 = odd;
                 head = head->next;
            }
            else
            {
            odd->next = head;
            odd = head;
            head = head->next;
            odd->next = NULL;
            }
        }
    }
    odd->next = n1;
    even->next = NULL;
    return n2;
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

int main()
{
    printf("Enter the linked list: ");
    listNode* head = createList();
    printf("\nOdd Even Sorted List: ");
    head = oddEvenList(head);
    printLinkedList(head);
    return 0;
}
