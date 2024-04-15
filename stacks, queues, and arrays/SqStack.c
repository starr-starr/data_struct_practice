#define MaxSize 10  
#include<stdio.h>  
#include<stdbool.h>  
  
typedef struct{  
    int data[MaxSize];  
    int top;  
} SqStack;  
  
void initStack(SqStack *s){ 
    s->top = -1; 
}  
  
bool isEmpty(SqStack *s){   
    if(s->top == -1){  
        return true;  
    }else{  
        return false;  
    }  
}  
  
bool push(SqStack *s, int element){ 
    if(s->top == MaxSize - 1){  
        return false;  
    }else{  
        s->top++;
        s->data[s->top] = element;  
        return true;  
    }  
}  
  
bool pop(SqStack *s, int *element){ 
    if(isEmpty(s)){ 
        return false;  
    }else{  
        *element = s->data[s->top];  
        s->top--;
        return true;  
    }  
}  
  
bool getTop(SqStack *s, int *element){
    if(isEmpty(s)){  
        return false;  
    }else{  
        *element = s->data[s->top];  
        return true;  
    }  
}  
  
int main(){  
    SqStack stack;  
    int element,i;  
      
    // 初始化栈  
    initStack(&stack);  
      
    // 测试isEmpty  
    if(isEmpty(&stack)){  
        printf("Stack is empty.\n");  
    }else{  
        printf("Stack is not empty.\n");  
    }  
      
    // 测试push  
    if(push(&stack, 5)){  
        printf("Pushed 5 into the stack.\n");  
    }else{  
        printf("Failed to push 5 into the stack.\n");  
    }  
      
    // 再次测试isEmpty  
    if(isEmpty(&stack)){  
        printf("Stack is empty.\n");  
    }else{  
        printf("Stack is not empty.\n");  
    }  
      
    // 测试push多个元素  
    for(i = 1; i <= MaxSize; i++){  
        if(push(&stack, i)){  
            printf("Pushed %d into the stack.\n", i);  
        }else{  
            printf("Failed to push %d into the stack (stack is full).\n", i);  
            break;  
        }  
    }  
      
    // 测试pop  
    if(pop(&stack, &element)){  
        printf("Popped %d from the stack.\n", element);  
    }else{  
        printf("Failed to pop from the stack (stack is empty).\n");  
    }  
      
    // 测试getTop  
    if(getTop(&stack, &element)){  
        printf("Top element is %d.\n", element);  
    }else{  
        printf("Failed to get top element (stack is empty).\n");  
    }  
      
    // 清理栈，直到空  
    while(!isEmpty(&stack)){  
        if(pop(&stack, &element)){  
            printf("Popped %d from the stack.\n", element);  
        }  
    }  
      
    // 再次测试isEmpty  
    if(isEmpty(&stack)){  
        printf("Stack is empty after cleanup.\n");  
    }else{  
        printf("Stack is not empty after cleanup.\n");  
    }  
      
    return 0;  
}
