#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i=0;
	printf("输入一个数:");
	scanf("%d", &i);
	if (i % 2 == 0){
		printf("偶数\n");
	}
	else{
		printf("奇数\n");
	}
	system("pause");
	return 0;
}

