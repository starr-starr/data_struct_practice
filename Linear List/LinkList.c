//  ������ 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// ����� LNode �� LNode *LinkList,һ���ǽṹ�壬һ����ָ��
// Ϊʲô����˳���ʱΪ
//      typedef struct {
//      	int *data;
//      	int MaxSize,length;
//      } SeqList;
// LNode �ǽṹ�屾�������֣�typedef ֻ�����������������Ҫ LNode Ӧ������Ϊ
// �ṹ�����ָ����Ҫָ����һ���ṹ�壬������д������
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//�����������
void printList(LinkList List){
    LinkList p = List;
    while(p -> next){
        p = p -> next;
        printf("%d ",p -> data);
    }
    printf("\n");
}

//��ʼ��������

// Ϊ�˴��������ͬ�����⣬һ�������һ��ͷ�������֤������һ���ԣ���ͷ���
// �� data ���ÿռ���
// ����ָ�����͵ı���������ͷ���ռ䣬ͷ����ָ�����ÿ�
bool initList(LinkList *List){
    *List = (LinkList)malloc(sizeof(LNode));
    if(List == NULL){
        printf("Memory allocation failed\n");
        return false;
    }
    (*List) -> next = NULL;
    return true;
}

//���
int Length(LinkList List){
    int length = 0;
    LinkList p = List;
    while(p -> next != NULL){
        length ++;
        p = p -> next;
    }
    return length;
}
//�������
// �ڰ�������У�����Ҫ�ҵ��ǵ� index ���ڵ㣬���������Ҫ���� index - 1 ��
// ֱ���ﵽĿ��ڵ��ǰһ���ڵ㡣��ÿ�ε����У����ǽ���ǰ�ڵ��ƶ���
// ��һ���ڵ㣬����������Ҫ��֤��ǰ�ڵ㲻Ϊ�գ�ͬʱ��һ���ڵ�Ҳ��Ϊ��
// �������ֻ�ж� p->next != NULL����ô�����һ�ε����У�p ��ָ�����һ��
// �ڵ�
// ��������Ҫ�������һ���ڵ����һ���ڵ㣬�� NULL��
// ��ˣ�����Ӧ���ж� p != NULL���Ա�֤�ڵ���������p ָ�����һ���ڵ��
// ��һ���ڵ㣬�� NULL��
LinkList getItemByIndex(LinkList List,int index){
    int i;
    LinkList p = List;
    if (index <= 0 || List == NULL) {
        printf("Invalid index\n");
        return NULL;
    }
    for(i = 1;p != NULL && i < index;i++){
        p = p -> next;
    }
    return p;
}
//��ֵ����,�����������
LinkList getItemByElement(LinkList List,int element){
    LinkList p = List;
    while(p->next != NULL && p -> data != element){
        p = p -> next;
    }
    return p;
}
//���
bool insertItem(LinkList List,int index,int element){
    LinkList p = List;
    int i;
    for(i = 1;p != NULL && i < index;i++){
        p = p -> next;
    }
    LinkList temp = (LinkList)malloc(sizeof(LNode));
    temp -> data = element;
    temp -> next = p -> next;
    p -> next = temp;
    return true;
}
//ɾ��
int deleteItem(LinkList List, int index) {
    LinkList p = List;
    int i;
    for (i = 1; p != NULL && i < index; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) {
        printf("Index out of range\n");
        return -1;
    }
    int element = p->next->data;
    LinkList temp = p->next;
    p->next = p->next->next;
    free(temp);
    temp = NULL;
    return element;
}
int main(){
    LinkList List,p;
    int i,l,j;
    initList(&List);
    for(i=0;i<5;i++){ 
        insertItem(List,i+1,i);
    }
    printf("Data after insertion: ");
    printList(List);
    p = getItemByIndex(List,2);
    printf("Data at index 2: ");
    printf("%d\n",p -> data);
    p = getItemByElement(List,2);
    printf("Data of the node with element 2: ");
    printf("%d\n",p -> data);
    l=Length(List);
    printf("Length of the list before delete: ");
    printf("%d\n",l);
    j = deleteItem(List,2);
    printf("Data deleted: %d\n",j);
    printf("Data after deletion: ");	
    printList(List);
    l=Length(List);
    printf("Length of the list after delete: ");
    printf("%d\n",l);
    return 0;
}



