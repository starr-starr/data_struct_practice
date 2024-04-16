//  单链表 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// 起别名 LNode 和 LNode *LinkList,一个是结构体，一个是指针
// 为什么声明顺序表时为
//      typedef struct {
//      	int *data;
//      	int MaxSize,length;
//      } SeqList;
// LNode 是结构体本来的名字，typedef 只是起个别名，这里需要 LNode 应该是因为
// 结构体里的指针需要指向下一个结构体，得事先写清名字
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//测试输出函数
void printList(LinkList List){
    LinkList p = List;
    while(p -> next){
        p = p -> next;
        printf("%d ",p -> data);
    }
    printf("\n");
}

//初始化单链表

// 为了处理操作不同的问题，一般会引入一个头结点来保证操作的一致性，该头结点
// 的 data 域置空即可
// 接收指针类型的变量，开辟头结点空间，头结点的指针域置空
bool initList(LinkList *List){
    *List = (LinkList)malloc(sizeof(LNode));
    if(List == NULL){
        printf("Memory allocation failed\n");
        return false;
    }
    (*List) -> next = NULL;
    return true;
}

//求表长
int Length(LinkList List){
    int length = 0;
    LinkList p = List;
    while(p -> next != NULL){
        length ++;
        p = p -> next;
    }
    return length;
}
//按序查找
// 在按序查找中，我们要找的是第 index 个节点，因此我们需要迭代 index - 1 次
// 直到达到目标节点的前一个节点。在每次迭代中，我们将当前节点移动到
// 下一个节点，所以我们需要保证当前节点不为空，同时下一个节点也不为空
// 如果我们只判断 p->next != NULL，那么在最后一次迭代中，p 将指向最后一个
// 节点
// 但我们需要的是最后一个节点的下一个节点，即 NULL。
// 因此，我们应该判断 p != NULL，以保证在迭代结束后，p 指向最后一个节点的
// 下一个节点，即 NULL。
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
//按值查找,返回整个结点
LinkList getItemByElement(LinkList List,int element){
    LinkList p = List;
    while(p->next != NULL && p -> data != element){
        p = p -> next;
    }
    return p;
}
//后插
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
//删除
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



