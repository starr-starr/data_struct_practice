// https://blog.csdn.net/kakahaoma/article/details/87874947

// ˳���
// ����Ϊ��̬�������Ϳ����µĿռ�

// �����ʼ����
#define INITSIZE 10
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// ����ṹ��
// ���ݼ�Ϊ int ���� & �ܳ��� & ĿǰԪ�ظ���
// ���Ϊ List* ����
typedef struct {
	int *data;
	int MaxSize,length;
} SeqList;
// ���Դ�ӡ����
void printList(SeqList *List){
	int i; 
    	for (i = 0; i < List -> length; i++){
        	printf("%d ", List -> data[i]);
    	}
    	printf("\n");
}
//��ʼ��˳���
//��Ϊ�Ƕ�̬���� �����Ҫ���� INITSIZE �ڴ�ռ䣬length Ϊ��ǰ����Ԫ�ظ���(0),MaxSize Ϊ��ǰ�� INITSIZE
//�����������Ϊ �ṹ������ �� �ṹ�壬��ֱ��ͨ�� obj.key ����
void initList(SeqList *List){
	List->data = (int *)malloc(sizeof(int) * INITSIZE);
	List->length = 0;
	List->MaxSize = INITSIZE;
}
// ����
// ��Ϊ����һ��ӵ�һλ��ʼ���룬����˵ʲô��0λ
// ����ʱ��0��ʼ��������Ϊ[0,length]��ת��Ϊλ�ü�Ϊ[1,lenth + 1],��Ϊֻ������Ԫ������²��ܲ��룬��������[] �ڵڶ�λ����Ԫ��1�������Ϊ[1,lenth + 1]
bool insertList(SeqList *List,int element,int index){
	int l;
	if (index < 1 || index > List->length + 1) {
		return false;
	}
	//�������鳤�Ȳ���,����2��
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
// ɾ��
int deleteList(SeqList *List,int index){
    int l,element;
    if(index < 1 || index > List->length ){
        return 0; // 0 ���� false
    }
    element = List->data[index-1];
    for(l = index - 1;l < List->length - 1;l++){
        List->data[l] = List->data[l + 1];    
    }
    List->length--;		
    return element;
}
// ����
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

