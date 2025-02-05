#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode* next;
}listNode;

typedef struct pQueue
{
    listNode* front;
    listNode* rear;
    int size;
}pQueue;



    pQueue* enqueue(pQueue* pq)
    {
        int val;
        scanf("%d",&val);
        listNode* node = (listNode*)malloc(sizeof(listNode));
        node->val = val;
        node->next = NULL;

        listNode* temp = pq->front;

        if(pq->rear == NULL)
        {
            pq->rear = node;
            pq->front = node;
            return pq;
        }
        if(node->val<(pq->front)->val)
        {
            node->next = pq->front;
            pq->front = node;
            return pq;
        }
        listNode* prev = temp;
        while(temp!=NULL && temp->val<=val)
        {
            prev = temp;
            temp = temp->next;
        }
        node->next = prev->next;
        prev->next = node;
        if((pq->rear)->next!=NULL)
        (pq->rear) = (pq->rear)->next;
        return pq;
    }

    void dequeue(pQueue **pq)
    {
        if((*pq)->front == NULL)
        {
            printf("PQ is Empty\n");
            return;
        }
        if((*pq)->front == (*pq)->rear)
        {
            (*pq)->front = NULL;
            (*pq)->rear = NULL;
            return;
        }
        (*pq)->front = ((*pq)->front)->next;
    }

    void peek(pQueue* pq)
    {
        if(pq->front == NULL)
        {
            printf("PQ is Empty\n");
            return;
        }
        printf("%d\n",(pq->front)->val);
    }

void displayQueue(pQueue* pq)
{
    if(pq->front == NULL)
    {
        printf("PQ is Empty\n");
        return;
    }
    listNode* temp = pq->front;
    while(temp)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
}
int main()
{
    pQueue* pq = (pQueue*)malloc(sizeof(pQueue));
    pq->front = NULL;
    pq->rear = NULL;

    while(1)
    {
        int choice;
        printf("Enter the operation:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display Queue\nExit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                pq = enqueue(pq);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                peek(pq);
                break;
            case 4:
                displayQueue(pq);
                break;
            default:
                exit(0);        
        }
    }

    return 0;
}
