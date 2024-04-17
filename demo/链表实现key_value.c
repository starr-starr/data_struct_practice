// ����ʵ�� key-value �ṹ 
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct Record {
    char *key;
    char *value;
} Record; 

typedef struct Node {
    Record dict;
    struct Node *next;
} Node, *List;

bool init(List *n) {
    *n = (List)malloc(sizeof(Node));
    if (*n == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }
    (*n)->next = NULL;
    return true;
}

void freeList(List n) {  
    while (n != NULL) {  
        List temp = n;  
        n = n->next;  
        free(temp->dict.key); // �ͷ�key�ַ����ڴ�
        free(temp->dict.value); // �ͷ�value�ַ����ڴ�
        free(temp);  
    }  
} 

void print(List n) {
    if (n == NULL || n->next == NULL) {
        printf("List is empty\n");
        return;
    }
    List p = n->next;
    while (p != NULL) {
        printf("%s:%s \n", (p->dict).key, (p->dict).value);
        p = p->next;
    }
//    printf("\n");
}

bool insert(List n, char *key, char *value) { // �޸Ĳ��뺯����������
    List p = n;
    while (p->next != NULL) {
        p = p->next;
    }
    List temp = (List)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }
    temp->dict.key = (char *)malloc((strlen(key) + 1) * sizeof(char)); // Ϊkey�ַ��������ڴ�
    temp->dict.value = (char *)malloc((strlen(value) + 1) * sizeof(char)); // Ϊvalue�ַ��������ڴ�
    if (temp->dict.key == NULL || temp->dict.value == NULL) {
        printf("Memory allocation failed\n");
        free(temp->dict.key);
        free(temp->dict.value);
        free(temp);
        return false;
    }
    strcpy(temp->dict.key, key); // ʹ��strcpy���������ַ���
    strcpy(temp->dict.value, value); // ʹ��strcpy���������ַ���
    temp->next = NULL;
    p->next = temp;
    return true;
}

int main() {
    List n;
    int len, i; 
    init(&n);
    // ��������һ����key��һ����value������index��һһ��Ӧ 
    char *key[] = {"1", "2","3"};  
    char *value[] = {"һ", "��","����"};
    len = sizeof(key) / sizeof(key[0]);
    for (i = 0; i < len; i++) {  
        if (!insert(n, key[i], value[i])) {
            printf("Failed to insert key-value pair\n");
            return 1;
        }
    } 
    print(n);
    freeList(n);
    return 0;
}

