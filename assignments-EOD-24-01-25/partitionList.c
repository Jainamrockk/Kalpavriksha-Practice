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

    int value;
    while (1)
    {
        scanf("%d", &value);
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

void printList(listNode *head)
{
    while (head)
    {
        printf("%d", head->val);
        head = head->next;
        if (head != NULL)
            printf("->");
    }
}

listNode *partitionList(listNode *head, int target)
{
    if (head == NULL || head->next == NULL)
        return head;

    listNode *left = NULL,*n1 = NULL;
    listNode *right = NULL,*n2 = NULL;
    listNode *equal = NULL,*n3 = NULL;
    int index1 = 0, index2 = 0;

    while (head)
    {
        if(head->val<target)
        {
            if(left == NULL)
            {
                left = head;
                n1 = head;
            }
            else
            {
                left->next = head;
                left = head;
            }
        }
        else if(head->val == target)
        {
             if(equal == NULL)
            {
                equal = head;
                n3 = head;
            }
            else
            {
                equal->next = head;
                equal = head;
            }
        }
        else
        {
            if(right == NULL)
            {
                right = head;
                n2 = head;
            }
            else
            {
                right->next = head;
                right = head;
            }
        }
        head = head->next;
    }
    if(left!=NULL)
    left->next = n3;
    if(equal!=NULL)
    equal->next = n2;
    if(right!=NULL)
    right->next = NULL;
    return (n1 != NULL)?n1:((n3!=NULL)?n3:(n2!=NULL)?n2:NULL);
}

int main()
{
    int partition;
    listNode *head = createList();
    scanf("%d", &partition);
    printf("Current List: ");
    printList(head);
    printf("\nAfter Partitioning List About %d: ", partition);
    head = partitionList(head, partition);
    printList(head);
    return 0;
}