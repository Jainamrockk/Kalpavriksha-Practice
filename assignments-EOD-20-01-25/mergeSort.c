#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{

    int data;
    struct ListNode *next;
} ListNode;

ListNode *createList()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (1)
    {
        int value;
        scanf("%d", &value);

        if (head == NULL)
        {
            head = (ListNode *)malloc(sizeof(ListNode *));
            head->data = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            ListNode *node = (ListNode *)malloc(sizeof(ListNode *));
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

void printLinkedList(ListNode *head)
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
ListNode *merge(ListNode *left,ListNode* right)
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

ListNode *calcMid(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = slow->next;
    slow->next = NULL;
    return temp;
}

ListNode *mergeSort(ListNode *left)
{
    if (left == NULL || left->next == NULL)
        return left;
    ListNode* mid = calcMid(left);   
    left = mergeSort(left);
    mid = mergeSort(mid);
    left = merge(left,mid);
    return left; 
}

int main()
{
    printf("Enter the linked list: ");
    ListNode *head = createList();
    head = mergeSort(head);
    printf("Sorted Linked List is: ");
    printLinkedList(head);
    return 0;
}
