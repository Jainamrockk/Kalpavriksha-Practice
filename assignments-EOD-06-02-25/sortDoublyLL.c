#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
    struct listNode *prev;
} listNode;

listNode *createList()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (1)
    {
        int value;
        scanf("%d", &value);
        listNode *newNode = (listNode *)malloc(sizeof(listNode));
        newNode->val = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
    return head;
}

listNode *findMid(listNode *temp)
{
    if (!temp || !temp->next)
        return temp;
    listNode *fast = temp;
    listNode *slow = temp;

    while (!fast && !fast->next)
    {
        fast = fast->next->next;
        if (!fast)
            slow = slow->next;
    }
    listNode *nn = slow->next;
    slow->next = NULL;
    if(nn!=NULL)
    nn->prev = NULL;
    return nn;
}

listNode *merge(listNode *left, listNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->val <= right->val)
    {
        left->next = merge(left->next, right);
        if(left->next!=NULL)
        left->next->prev = left;
        return left;
    }
    right->next = merge(left, right->next);
     if(right->next!=NULL)
        right->next->prev = right;
    return right;
}

listNode *mergeSort(listNode *head)
{
    if (!head || !head->next)
        return head;

    listNode *mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head, mid);
    return head;
}

void printLinkedList(listNode *head)
{
    while (head->next)
    {
        // printf("%d->",head->val);
        head = head->next;
    }
    while (head)
    {
        printf("%d->", head->val);
        head = head->prev;
    }
}

int main()
{
    listNode *head = createList();
    head = mergeSort(head);
    printLinkedList(head);
    return 0;
}