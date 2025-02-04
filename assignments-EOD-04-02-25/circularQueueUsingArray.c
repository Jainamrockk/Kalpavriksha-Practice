#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int* arr;
    int front;
    int rear;
    int capacity;
}queue;

int size(queue* q)
{
    if(q->front == -1)
    return -1;
    return (abs(q->rear%q->capacity - q->front%q->capacity) + 1);
}

void dequeue(queue* q)
{
    if(size(q) == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    ++q->front;
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

void enqueue(queue* q)
{
    int value;
    scanf("%d",&value);
    if(size(q) == q->capacity)
    {
        printf("Queue is Full\n");
        return;
    }
    if(q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear%q->capacity] = value;

}

void displayFront(queue* q)
{
    if(q->front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    printf("Front: %d\n",q->arr[q->front%q->capacity]);
}


void displayRear(queue* q)
{
    if(q->rear == -1)
    {
        printf("Queue Underflow");
        return;
    }
    printf("Rear: %d\n",q->arr[q->rear%q->capacity]);
}

int main()
{
    queue* q = (queue*)malloc(sizeof(queue)*100);
    q->front = -1;
    q->rear = -1;
    int capacity;
    scanf("%d",&capacity);
    q->capacity = capacity;
    q->arr = (int*)malloc(sizeof(int)*q->capacity);

    while(1)
    {
        int choice;
        printf("Enter the Operation:\n1. Enqueue\n2. Dequeue\n3. Display Last Element\n4. Display First Element\n5. Size\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayFront(q);
                break;   
            case 4:
                displayRear(q);
                break; 
            case 5:
                printf("Size of Circular Queue is: %d\n",size(q));
                break;       
            default:
                exit(0);         
        }
    }


    return 0;
}


