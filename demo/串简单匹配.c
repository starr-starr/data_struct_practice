#include <stdio.h>  
#include <string.h>  
  
// 简单模式匹配算法  
int simpleMatch(char* str, char* pattern) {  
    int strLen = strlen(str);  
    int patternLen = strlen(pattern);  
  	int i=0,j=0;
  	
  	while(i<strLen){
  		if( str[i] == pattern[j] ){
  			i++;
  			j++;
  			if(j==patternLen){
				return i-patternLen;
			}
  			printf("%d %d\n",i,j); 
		  }else{
		  	i=i-j+1;
		  	j=0;
		  }
	  }
	return -1;
   
}  
  
int main() {  
   	char str[] = "banana";  
	char pattern[] = "anana";
    int pos = simpleMatch(str, pattern);  
    if (pos != -1) {  
        printf("Pattern found at position: %d\n", pos);  
    } else {  
        printf("Pattern not found in the string\n");  
    }  
    return 0;  
}
