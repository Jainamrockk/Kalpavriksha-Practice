#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
    struct listNode *bottom;
} listNode;

listNode *createColumns()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (1)
    {
        int value;
        scanf("%d", &value);
        if (head == NULL)
        {
            head = (listNode *)malloc(sizeof(listNode));
            head->val = value;
            head->next = NULL;
            tail = head;
        }
        else{
        listNode *node = (listNode *)malloc(sizeof(listNode));
        node->val = value;
        node->next = NULL;
        tail->next = node;
        tail = node;
        }
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    return head;
}

listNode *createLinkedList(listNode *col)
{
    listNode *head = NULL;
    listNode *tail = NULL;

    while (col)
    {
        listNode* node = NULL;
        listNode* nodeTail = NULL;
        while (col->val)
        {
            int value;
            scanf("%d", &value);
            col->val = col->val - 1;
            if(node == NULL)
            {
                node = (listNode*)malloc(sizeof(listNode));
                node->val = value;
                node->next = NULL;
                node->bottom = NULL;
                nodeTail = node;
                continue;
            }
            listNode* colNode = (listNode*)malloc(sizeof(listNode));
            colNode->val = value;
            colNode->next = NULL;
            colNode->bottom = NULL;
            nodeTail->bottom = colNode;
            nodeTail = colNode;
        }
        col = col->next;
        if(head == NULL)
        {
            head = node;
            tail = node;
            continue;
        }
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    return head;
}

void printLinkedList(listNode* head)
{
    while(head)
    {
        listNode *temp = head;
        while(temp)
        {
            printf("%d",temp->val);
           if(temp->bottom!=NULL)
           {
            printf("->");
           }
            temp = temp->bottom;
        }
        if(head->next!=NULL)
        {
            printf("\n|\n");
        }
        head = head->next;
    }

}

void printLL(listNode* head)
{
    while(head)
    {
        printf("%d ",head->val);
        head = head->next;
    }
}


listNode* merge(listNode *left, listNode *right)
{
    if(!left) return right;
    if(!right) return left;

    if(left->val<=right->val)
    {
        left->bottom = merge(left->bottom,right);
        return left;
    }
    right->bottom = merge(left,right->bottom);
    return right;
}

listNode *flatten(listNode *head)
{
    if(!head || !head->next)
    return head;

    head->next = flatten(head->next);
    head = merge(head,head->next);
    head->next = NULL;
    return head;
}

int main()
{
    listNode *col = createColumns();
    listNode *head = createLinkedList(col);
    head = flatten(head);
    printLinkedList(head);
    return 0;
}