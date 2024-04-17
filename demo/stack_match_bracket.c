#define MaxSize 10 
#include<stdio.h> 
#include <string.h>
#include<stdbool.h> 

typedef struct{  
    char data[MaxSize];  
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

bool push(SqStack *s, char element){ 
    if(s->top == MaxSize - 1){  
        return false;  
    }else{  
        s->top++;
        s->data[s->top] = element;  
        return true;  
    }  
}  
  
bool pop(SqStack *s, char *element){ 
    if(isEmpty(s)){ 
        return false;  
    }else{  
        *element = s->data[s->top];  
        s->top--;
        return true;  
    }  
}  

int main(){
	SqStack s;
 	char str[10];
 	int len,i;
	scanf("%s",str);
	len = strlen(str);
	initStack(&s);
	for(i=0;i<len;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			push(&s,str[i]);
		}else{
			if(isEmpty(&s)){
				printf("Æ¥ÅäÊ§°Ü£¡");
				return 0;
			}
			char element;
			pop(&s,&element);
			if( (element=='('&& str[i]==')') || (element=='['&& str[i]==']') || (element=='{'&& str[i]=='}') ){
				continue;
			}else{
				printf("Æ¥ÅäÊ§°Ü£¡");
				return 0;
			} 
		}
	}
	if(isEmpty(&s)){
		printf("ÍêÈ«Æ¥Åä£¡"); 
	}else{
		printf("Æ¥ÅäÊ§°Ü£¡"); 
	}
	return 0;
}
