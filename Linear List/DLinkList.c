//  ˫���� 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DNode {
    int data;
    struct DNode *prior,*next;
} DNode, *DLinkList;

//�����������
void printList(DLinkList List){
    DLinkList p = List;
    while(p -> next){
        p = p -> next;
        printf("%d ",p -> data);
    }
    printf("\n");
}

bool initList(DLinkList *List){
    *List = (DLinkList)malloc(sizeof(DNode));
    if(List == NULL){
        printf("Memory allocation failed\n");
        return false;
    }
    (*List) -> prior = NULL;
    (*List) -> next = NULL;
    return true;
}

//�������
DLinkList getItemByIndex(DLinkList List,int index){
	int j=1;
    DLinkList p = List -> next;
    if(index==0)return List;
    if(index<1)return NULL;
    while(p && j<index){
        p = p->next;
        j++;
    }
    return p;
}


// ��ָ֪�������½��� data ֵ����ָ���ڵ������½ڵ� 
DLinkList insertItem(DLinkList List,DLinkList s,int element){
    DLinkList temp = (DLinkList)malloc(sizeof(DNode));
    temp -> data = element;
    temp -> next = s -> next;
    temp -> prior = s;
    s -> next -> prior = temp;
    s -> next = temp;
    return temp;
}

//ɾ��ĳ����֪���ĺ�̽�� 
int deleteItem(DLinkList List,DLinkList s) {
    DLinkList temp = s->next;
    int element = temp->data;
    s->next = temp->next;
	temp->next->prior = s; 
    free(temp);
    temp = NULL;
    return element;
}

//β�巨����˫����
DLinkList TailInsert(DLinkList L){
    initList(&L);
    DNode *s,*r=L;
    int i;
    for(i=0;i<5;i++){ 
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = i;
        s->next = NULL;
        s->prior = r;
        r->next = s;
        r = s;
    }
    return L;
}

int main(){
    DLinkList List,p;
    int i,j;
    List = TailInsert(List);
    printf("Data after insertion: ");
    printList(List);
    p = getItemByIndex(List,3);
    printf("Data of the node 3: %d\n",p->data);
    p = insertItem(List,p,666);
    printf("Data after insertion: ");
    printList(List);
    j = deleteItem(List,p);
    printf("Data deleted: %d\n",j);
    printf("Data after delete which after j node: ");	
    printList(List);
    return 0;
}
