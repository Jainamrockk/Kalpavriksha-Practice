#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{

    int data;
    struct listNode *next;
} listNode;

listNode *createList()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (1)
    {
        int value;
        scanf("%d", &value);

        if (head == NULL)
        {
            head = (listNode *)malloc(sizeof(listNode *));
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            listNode *node = (listNode *)malloc(sizeof(listNode *));
            node->data = value;
            tail->next = node;
            tail = tail->next;
            tail->next = NULL;
        }

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }
    return head;
}

void printLinkedList(listNode *head)
{
    if (head == NULL)
    {
        printf("Empty");
    }
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
listNode *merge(listNode *left,listNode* right)
{

    if(left == NULL) return right;
    if(right == NULL) return left;

    if(left->data<=right->data)
    {
        left->next = merge(left->next,right);
        return left;
    }
    right->next = merge(left,right->next);
    return right;
}

listNode *calcMid(listNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    listNode *slow = head;
    listNode *fast = head->next;
    while (fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    listNode* temp = slow->next;
    slow->next = NULL;
    return temp;
}

listNode *mergeSort(listNode *left)
{
    if (left == NULL || left->next == NULL)
        return left;
    listNode* mid = calcMid(left);   
    left = mergeSort(left);
    mid = mergeSort(mid);
    left = merge(left,mid);
    return left; 
}

int main()
{
    printf("Enter the linked list: ");
    listNode *head = createList();
    head = mergeSort(head);
    printf("Sorted Linked List is: ");
    printLinkedList(head);
    return 0;
}
