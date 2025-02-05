#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
}queue;

int size(queue* q)
{
    return q->size;
}

void dequeue(queue* q)
{
    if(q->front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }    
    else if(q->front == q->rear)
    {
        q->front = 0;
        q->rear = 0;
        q->size = 1;
    }
    else if(q->front == q->capacity - 1)
    {
        q->front = 0;
    }
    else
    q->front++;
    q->size--;
}

void enqueue(queue* q)
{
    int value;
    scanf("%d",&value);
    if((q->front == 0 && q->rear == q->capacity - 1) || (q->rear == (q->front - 1)%(q->capacity)))
    {
        printf("%d %d\n",q->front,q->rear);
        printf("Queue is Full\n");
        return;
    }
    else if(q->front == -1)
    {
        q->front = 0;
        q->rear++;
    }
    else if(q->rear == q->capacity - 1 && q->front!=0)
    {
        q->rear = 0;
        q->size = -1;
    }
    else
    q->rear++;

    q->arr[q->rear%q->capacity] = value;
    q->size++;
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

void displayQueue(queue* q)
{
    int index = q->front;
    while(index!=q->rear)
    {
        printf("%d ",q->arr[index]);
        index = (index+1)%q->capacity;
    }
    if(index>=0)
    {
        printf("%d ",q->arr[index]);
    }
    printf("\n");
}

int main()
{
    queue* q = (queue*)malloc(sizeof(queue)*100);
    q->front = -1;
    q->rear = -1;
    int capacity;
    printf("Enter capacity: ");
    scanf("%d",&capacity);
    q->capacity = capacity;
    q->arr = (int*)malloc(sizeof(int)*q->capacity);
    q->size = 0;
    while(1)
    {
        int choice;
        printf("Enter the Operation:\n1. Enqueue\n2. Dequeue\n3. Display Last Element\n4. Display First Element\n5. Size\n6. Display Queue\n");
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
            case 6:
                displayQueue(q);
                break;       
            default:
                exit(0);         
        }
    }


    return 0;
}


