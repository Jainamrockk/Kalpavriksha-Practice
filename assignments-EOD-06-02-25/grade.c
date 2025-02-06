#include <stdio.h>
#include <stdlib.h>

typedef enum grade
{
    A=1,
    B,
    C,
    D,
    F
} grade;

typedef struct studentNode
{
    char *name;
    grade grade;
    struct studentNode *next;

} studentNode;

int stringCmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

studentNode *createList()
{
    studentNode *head = NULL;
    studentNode *tail = NULL;

    while (1)
    {
        char *name = (char *)malloc(sizeof(char) * 100);
        char grade;
        studentNode *node = (studentNode *)malloc(sizeof(studentNode));
        scanf("%s %c", name, &grade);
        node->name = name;
        if (grade - 'A' == 6)
            node->grade = F;
        else
        {
            node->grade = grade - 'A'+1;
        }
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
    return head;
}

studentNode *findMid(studentNode *head)
{
    if (!head || !head->next)
        return head;

    studentNode *fast = head;
    studentNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        if (fast)
        {
            slow = slow->next;
        }
    }
    studentNode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

studentNode *merge(studentNode *left, studentNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;
    if (left->grade < right->grade)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else if (left->grade == right->grade)
    {
        if (stringCmp(left->name, right->name) <= 0)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
    right->next = merge(left, right->next);
    return right;
}

studentNode *mergeSort(studentNode *head)
{
    if (!head || !head->next)
        return head;
    studentNode *mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head, mid);
    return head;
}

void printList(studentNode *head)
{
    while (head != NULL)
    {
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main()
{

    studentNode *head = createList();
    head = mergeSort(head);
    printList(head);
    return 0;
}
