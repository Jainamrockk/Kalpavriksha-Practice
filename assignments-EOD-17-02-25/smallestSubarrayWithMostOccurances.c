#include <stdio.h>
#include <stdlib.h>

typedef struct hashNode {
    int key;
    int value[3];
    struct hashNode* next;
} hashNode;

hashNode** hashMap;
int size = 0, maxNum = 0, maxCount = 0;

int hash(int key) {
    return (size + (key) % size) % size;
}

int* stringToArr(char* str, int* arrSize) {
    int* arr = (int*)malloc(sizeof(int) * 1000);
    int num = 0, isNegative = 0, count = 0;

    while (*str != '\0') {
        char ch = *str;
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + ch - '0';
        } else if (ch == '-') {
            isNegative = 1;
        } else if (ch == ',' || ch == ']') {
            if (isNegative) {
                num = -num;
                isNegative = 0;
            }
            arr[count++] = num;
            num = 0;
        }
        str++;
    }

    *arrSize = count; 
    arr = (int*)realloc(arr, sizeof(int) * count);
    return arr;
}

void insert(int key, int idx) {
    int index = hash(key);
    hashNode* temp = hashMap[index];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->value[0]++;
            if (maxCount < temp->value[0]) {
                maxCount = temp->value[0];
                maxNum = key;
            }
            temp->value[2] = idx;
            return;
        }
        temp = temp->next;
    }

    hashNode* node = (hashNode*)malloc(sizeof(hashNode));
    node->key = key;
    node->value[0] = 1;
    node->value[1] = idx;
    node->value[2] = idx;
    node->next = hashMap[index];
    hashMap[index] = node;
}

void insertIntoMap(int* arr, int arrSize) {
    for (int index = 0; index < arrSize; index++) {
        insert(arr[index], index);
    }
}

void freeHashMap() {
    for (int i = 0; i < size; i++) {
        hashNode* temp = hashMap[i];
        while (temp) {
            hashNode* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(hashMap);
}

int main() {
    char* str = (char*)malloc(sizeof(char)*1000);
    scanf("%[^\n]%*c", str);

    int arrSize;
    int* arr = stringToArr(str, &arrSize);

    size = arrSize > 0 ? arrSize : 1;
    hashMap = (hashNode**)calloc(size, sizeof(hashNode*));

    insertIntoMap(arr, arrSize);

    if (hashMap[hash(maxNum)] != NULL) {
        printf("[%d,%d]\n", hashMap[hash(maxNum)]->value[1], hashMap[hash(maxNum)]->value[2]);
    }

    free(arr);
    freeHashMap();
    return 0;
}
