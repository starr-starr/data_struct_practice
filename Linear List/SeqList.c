// https://blog.csdn.net/kakahaoma/article/details/87874947

// 顺序表
// 长度为动态，不够就开辟新的空间

// 定义初始长度
#define INITSIZE 10
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// 定义结构体
// 数据简化为 int 类型 & 总长度 & 目前元素个数
// 结果为 List* 类型
typedef struct {
	int *data;
	int MaxSize,length;
} SeqList;
// 测试打印函数
void printList(SeqList *List){
	int i; 
    	for (i = 0; i < List -> length; i++){
        	printf("%d ", List -> data[i]);
    	}
    	printf("\n");
}
//初始化顺序表
//因为是动态分配 因此需要开辟 INITSIZE 内存空间，length 为当前数组元素个数(0),MaxSize 为当前的 INITSIZE
//传入参数类型为 结构体类型 的 结构体，可直接通过 obj.key 操作
void initList(SeqList *List){
	List->data = (int *)malloc(sizeof(int) * INITSIZE);
	List->length = 0;
	List->MaxSize = INITSIZE;
}
// 插入
// 因为插入一般从第一位开始插入，不会说什么第0位
// 插入时从0开始插入区间为[0,length]，转换为位置即为[1,lenth + 1],因为只有在有元素情况下才能插入，不可能像“[] 在第二位插入元素1”，因此为[1,lenth + 1]
bool insertList(SeqList *List,int element,int index){
	int l;
	if (index < 1 || index > List->length + 1) {
		return false;
	}
	//处理数组长度不够,扩容2倍
	if (List->length == List->MaxSize) {
		int newMaxSize = 2 * List->MaxSize;
		int *newData = realloc(List->data, sizeof(int) * newMaxSize);
		if (newData == NULL) {
			return false; // realloc ?  
		}
		List->data = newData;
		List->MaxSize = newMaxSize;
	}
	for (l = List->length; l > index; l--) {
		List->data[l] = List->data[l - 1];
	}
	List->data[index - 1] = element;
	List->length++;
	return true;
}
// 删除
int deleteList(SeqList *List,int index){
    int l,element;
    if(index < 1 || index > List->length ){
        return 0; // 0 代表 false
    }
    element = List->data[index-1];
    for(l = index - 1;l < List->length - 1;l++){
        List->data[l] = List->data[l + 1];    
    }
    List->length--;		
    return element;
}
// 查找
int findItem(SeqList *List,int element){
    int i;
    for(i=0;i<List->length;i++){
        if(List->data[i] == element ){
            return i+1;
        }
    }
    return 0;
}
int main(){  
    SeqList List;  
    initList(&List);  
    int i, e, index;  
    for (i = 0; i < 9; i++){  
        if (!insertList(&List, i, i + 1)) {  
            printf("Insertion failed\n");  
            break;  
        }  
    }  
    printf("Elements after insertion: ");  
    printList(&List);  
    e = deleteList(&List, 3);  
    printf("Deleted element: %d\n", e);  
    printf("Elements after deletion: ");  
    printList(&List);  
    index = findItem(&List, 5);  
    printf("Position of element 5: %d \n", index);  
    free(List.data);  
    return 0;  
}

