#define MaxSize 10    
#include<stdio.h>    
#include<stdlib.h>
#include<stdbool.h>  
  
// 所有的取模操作都是因为适配 MaxSize 
// 牺牲了一个空间来区分队满/队空 
  
typedef struct SqQuenu{  
    int data[MaxSize];  
    int front, rear;  
} SqQuenuNode, *SqQuenu;   
  
void initSqQuenu(SqQuenu *s){  
    *s = (SqQuenu)malloc(sizeof(SqQuenuNode));  
    if(*s == NULL){  
        printf("Memory allocation failed\n");  
        return;  
    }  
    (*s)->front = (*s)->rear = 0;  
}  
  
void destroySqQuenu(SqQuenu *s){  
    free(*s);  
    *s = NULL;  
}  
  
bool isEmpty(SqQuenu s){  
    return s->rear == s->front;  
}  
  
bool enqueue(SqQuenu s, int element){  
    if((s->rear + 1) % MaxSize == s->front){  
        return false;  
    }  
    s->data[s->rear] = element;  
    s->rear = (s->rear + 1) % MaxSize;  
    return true;  
}  
  
bool dequeue(SqQuenu s, int *element){  
    if(isEmpty(s)){  
        return false;  
    }  
    *element = s->data[s->front];  
    s->front = (s->front + 1) % MaxSize;  
    return true;  
}  
  
void printQueue(SqQuenu s){  
    if(isEmpty(s)){  
        printf("Queue is empty.\n");  
        return;  
    }  
    printf("Queue elements: ");  
    int i = s->front;  
    while(i != s->rear){  
        printf("%d ", s->data[i]);  
        i = (i + 1) % MaxSize;  
    }  
    printf("\n");  
}  
  
int main(){  
    SqQuenu s;  
    initSqQuenu(&s);  
   
    if(enqueue(s, 1)){  
        printf("Enqueued 1 successfully.\n");  
    }else{  
        printf("Failed to enqueue 1.\n");  
    }  
    if(enqueue(s, 2)){  
        printf("Enqueued 2 successfully.\n");  
    }else{  
        printf("Failed to enqueue 2.\n");  
    }  
    if(enqueue(s, 3)){  
        printf("Enqueued 3 successfully.\n");  
    }else{  
        printf("Failed to enqueue 3.\n");  
    }  
   
    printQueue(s);  
   
    int dequeuedElement;  
    if(dequeue(s, &dequeuedElement)){  
        printf("Dequeued element: %d\n", dequeuedElement);  
    }else{  
        printf("Queue is empty, cannot dequeue.\n");  
    }  
  
    printQueue(s);  
   
    destroySqQuenu(&s);  
  
    return 0;  
}
