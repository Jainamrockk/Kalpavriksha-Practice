#include<stdio.h>
#include<stdlib.h>

typedef enum passengerType
{
    GENERAL,
    SENIOR_CITIZEN,
    VIP
}passengerType;

typedef struct passenger
{
    int passengerID;
    passengerType type;
    char* passengerName;
}passenger;

typedef struct passengerList
{
    passenger **passengerQueue;
    int front;
    int rear;
    int capacity;
    int size;
}passengerList;

char* passengerTypeName[3];

void displayQueue(passengerList*);

void initializePassengerTypeName()
{
    passengerTypeName[0] = (char*)malloc(sizeof(char)*10);
    passengerTypeName[1] = (char*)malloc(sizeof(char)*20);
    passengerTypeName[2] = (char*)malloc(sizeof(char)*10);
    passengerTypeName[0] = "GENERAL";
    passengerTypeName[1] = "SENIOR_CITIZEN";
    passengerTypeName[2] = "VIP";
}

int isEmpty(passengerList* passengerMemo)
{
    return (passengerMemo->front == -1);
}

int isFull(passengerList* passengerMemo)
{
    return (passengerMemo->rear == passengerMemo->capacity-1);
}

int strCmp(char* s1,char* s2)
{
    while(*s1!='\0' && *s2!='\0')
    {
        if(*s1!=*s2)
        return *s1-*s2;
        s1++;
        s2++;
    }
    return *s1-*s2;
}

void merge(passenger** arr,int left,int mid,int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    passenger** arr1 = (passenger**)malloc(sizeof(passenger)*size1);
    passenger** arr2 = (passenger**)malloc(sizeof(passenger)*size2);
    int mergeIndex = left;
    for(int index=0;index<size1;index++)
    {
        arr1[index] = arr[mergeIndex++];
    }
    for(int index = 0;index<size2;index++)
    {
        arr2[index] = arr[mergeIndex++];
    }
    int index1=0,index2=0;
    mergeIndex = left;
    while(index1<size1 && index2<size2)
    {
        if(arr1[index1]->type>=arr2[index2]->type)
        {
            arr[mergeIndex++] = arr1[index1++];
        }
        else
        {
            arr[mergeIndex++] = arr2[index2++];
        }
    }
    while(index1<size1)
    {
         arr[mergeIndex++] = arr1[index1++];
    }
     while(index2<size2)
    {
         arr[mergeIndex++] = arr2[index2++];
    }
    free(arr1);
    free(arr2);
}

void mergeSort(passenger** arr,int left,int right)
{
    if(left>=right)
    return;
    int mid = (right-left)/2 + left;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void enqueue(passengerList* passengerMemo)
{
    if(isFull(passengerMemo))
    {
        passengerMemo->capacity *=2;
        passengerMemo->passengerQueue = (passenger**)realloc(passengerMemo->passengerQueue,sizeof(passenger*)*passengerMemo->capacity);
    }
    int pId;
    char* name = (char*)malloc(sizeof(char)*100);
    char* passengerType = (char*)malloc(sizeof(char)*15);

    scanf(",%d, %[^,], \"%[^\"]\";", &pId, passengerType, name);
    // scanf(",%d,",&pId);
    // scanf("%s,",passengerType);
    // scanf("\"%[^\"]\";",name);
    if(passengerMemo->front == -1)
    {
        passengerMemo->front = 0;
    }
    passenger* newPassenger = (passenger*)malloc(sizeof(passenger));
    newPassenger->passengerID = pId;
    newPassenger->passengerName = name;
    if(strCmp(passengerType,"GENERAL") == 0)
    newPassenger->type= GENERAL;
    else if(strCmp(passengerType,"SENIOR_CITIZEN") == 0)
    newPassenger->type = SENIOR_CITIZEN;
    else if(strCmp(passengerType,"VIP") == 0)
    newPassenger->type = VIP;
    else
    {
        printf("Enter Valid Passenger Type.\n");
        return;
    }

    passengerMemo->passengerQueue[++passengerMemo->rear] = newPassenger;
    passengerMemo->size++;
    mergeSort(passengerMemo->passengerQueue,passengerMemo->front,passengerMemo->rear);
}

void displayQueue(passengerList* passengerMemo)
{
    printf("Waiting Passengers:\n");
    if(isEmpty(passengerMemo))
    {
        printf("Empty\n");
        return;
    }

    for(int index = passengerMemo->front;index<=passengerMemo->rear;index++)
    {
        printf("ID %d, Name: %s, Type: %s\n",(passengerMemo->passengerQueue)[index]->passengerID,(passengerMemo->passengerQueue)[index]->passengerName,passengerTypeName[(passengerMemo->passengerQueue)[index]->type]);
    }
}


void createPassengerList(passengerList* passengerMemo)
{
    passengerMemo->front = -1;
    passengerMemo->rear = -1;
    passengerMemo->capacity = 100;
    passengerMemo->size = 0;
    passengerMemo->passengerQueue = (passenger**)malloc(sizeof(passenger*)*passengerMemo->capacity);
}

void dequeue(passengerList* passengerMemo)
{
    if(isEmpty(passengerMemo))
    {
        printf("Queue UnderFlow\n");
        return;
    }
    printf("Serving Passenger:\n");
     printf("ID %d, Name: %s, Type: %s\n",(passengerMemo->passengerQueue)[passengerMemo->front]->passengerID,(passengerMemo->passengerQueue)[passengerMemo->front]->passengerName,passengerTypeName[(passengerMemo->passengerQueue)[passengerMemo->front]->type]);
    passengerMemo->front++;
}

int main()
{
    int numberOfOperations;
    passengerList* passengerMemo = (passengerList*)malloc(sizeof(passengerList));
    passengerMemo->passengerQueue = NULL;
    createPassengerList(passengerMemo);
    scanf("%d",&numberOfOperations);
    initializePassengerTypeName();
    while(numberOfOperations)
    {
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue(passengerMemo);
            break;  
            case 2:
            dequeue(passengerMemo);
            break;
            case 3:
            displayQueue(passengerMemo);
            break;
            default:
            break;
        }
        numberOfOperations--;
    }
    return 0;

}