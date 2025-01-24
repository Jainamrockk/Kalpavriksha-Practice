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

void printList(listNode* head)
{
    while(head)
    {
        printf("%d",head->val);
        head = head->next;
        if(head!=NULL)
        printf("->");
    }
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

listNode* makeCircular(listNode* head)
{
    listNode* temp = head;
    while(head->next)
    {
        head = head->next;
    }
    head->next = temp;
    return temp;
}

listNode* rotateList(listNode* head,int numberOfRotations)
{
    if(head == NULL || head->next == NULL)
    return head;

    int length = listLength(head);
    numberOfRotations= numberOfRotations%length;
    head = makeCircular(head);
    listNode* temp = head;
    while(numberOfRotations!=1)
    {
        head = head->next;
        numberOfRotations--;
    }
    temp = head->next;
    head->next = NULL;

    return  temp;

}

int main()
{
    int numberOfRotations;
    listNode* head = createList();
    scanf("%d",&numberOfRotations);
    head = rotateList(head,numberOfRotations);
    printList(head);
    return 0;
}