#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print(int x){
	if (x <10){
		printf("%d\n", x);
	}
	else{
		print(x / 10);
		printf("%d\n", (x % 10));
	}
}
int main(){
	int i = 0;
	printf("请输入一个数：");
	scanf("%d", &i);
	print(i);
	system("pause");
	return 0;
}