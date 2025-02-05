#include <stdio.h>
#include <stdlib.h>

typedef enum availability
{
    OFFLINE,
    ONLINE
} availability;

typedef struct driverNode
{
    int id;
    availability mode;
    struct driverNode *next;
} driverNode;

int strCmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
char *driverStatus[2];
driverNode *driverHead;
driverNode *driverTail;
void initializeStatus()
{
    driverStatus[0] = (char *)malloc(sizeof(char) * 10);
    driverStatus[1] = (char *)malloc(sizeof(char) * 10);
    driverStatus[0] = "OFFLINE";
    driverStatus[1] = "ONLINE";
}

void addDriver()
{
    int id;
    char *mode = (char *)malloc(sizeof(char) * 10);
    scanf("\nD%d %s", &id, mode);
    driverNode *newDriver = (driverNode *)malloc(sizeof(driverNode));
    newDriver->id = id;
    newDriver->next = NULL;
    if (strCmp(mode, "ONLINE") == 0)
    {
        newDriver->mode = ONLINE;
    }
    else if (strCmp(mode, "OFFLINE") == 0)
    {
        newDriver->mode = OFFLINE;
    }
    else
    {
        printf("Enter Valid Mode\n");
        return;
    }
    if (driverHead == NULL)
    {
        driverHead = newDriver;
        driverTail = newDriver;
    }
    else
    {
        driverTail->next = newDriver;
        driverTail = newDriver;
    }
    driverTail->next = driverHead;
}

void createList(int totalDrivers)
{
    driverHead = NULL;
    driverTail = NULL;

    while (totalDrivers)
    {
        addDriver();
        totalDrivers--;
    }
}

void deleteDriver()
{
    driverNode *temp = driverHead;
    if (temp == NULL)
    {
        printf("Empty List\n");
        return;
    }
    int id;
    int flag = 0;
    printf("Enter driver to delete\n");
    scanf("\nD%d", &id);
    driverNode *prev = driverTail;
    while (temp->next != driverHead)
    {
        if (temp->id == id)
        {
            flag = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
  if(temp->id == id)
  {
    prev->next = temp->next;
    temp->next = NULL;
    free(temp);
  }

}


void assignRide()
{
    driverNode* temp = driverHead;
    if(temp == NULL)
    {
        printf("No Drivers\n");
        return;
    }

    int flag = 0;
    while(temp->next!=driverHead)
    {
        if(temp->mode == ONLINE)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 0)
    {
        if(temp->mode == ONLINE)
        {
   
            flag = 1;
        }
    }

    if(flag == 1)
    {
        printf("Ride Assigned to D%d\n",temp->id);
        temp->mode = 1 - temp->mode;
    }
    else
    {
        printf("No Drivers Available\n");
    }
}

void changeMode()
{
     driverNode *temp = driverHead;
    if (temp == NULL)
    {
        printf("Empty List\n");
        return;
    }
    int id;
    int flag = 0;
    printf("Enter driver to change Mode\n");
    scanf("\nD%d", &id);

    while (temp->next != driverHead)
    {
        if (temp->id == id)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
  if(temp->id == id)
  {
    temp->mode = 1 - temp->mode;
  }
}

void driverStatusPrint()
{
    if(driverHead == NULL)
    {
        printf("No Driver Present\n");
        return;
    }
    driverNode* temp = driverHead;
    while(temp->next!=driverHead)
    {
        printf("D%d (%s)\n",temp->id,driverStatus[temp->mode]);
        temp = temp->next;
    }
     printf("D%d (%s)\n",temp->id,driverStatus[temp->mode]);
}

int main()
{
    int totalDrivers;
    scanf("%d", &totalDrivers);
    createList(totalDrivers);
    initializeStatus();
    while (1)
    {
        printf("Enter the operation:\n1.Add Driver\n2.Delete Driver\n3.Assign Ride\n4.Change Mode\n5.Print Driver Status \n6.Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            addDriver();
            break;
            case 2:
            deleteDriver();
            break;
            case 3:
            assignRide();
            break;
            case 4:
            changeMode();
            break;
            case 5:
            driverStatusPrint();
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid Choice\n");
            break;
        }

    }
    return 0;
}