#include<stdio.h>
#include<stdlib.h>
//µİ¹é
int mystrlen(char* str){
	if (*str == '\0'){
		return 0;
	}
	else{
		return 1 + mystrlen(str + 1);
	}
}
//·Çµİ¹é
int mystrlen(char* str){
	int count=0;
	while (*str){
		++count;
		++str;
	}
	return count;
}
int main(){
	char arr[] = "abcde";
	printf("%d\n", mystrlen(arr));
	system("pause");
	return 0;
}