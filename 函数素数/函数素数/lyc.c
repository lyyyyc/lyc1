#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int sushu(int x){
	if (x <= 1){
		printf("不是素数\n");
		return 0;
	}
	for (int i = 2; i < x; ++i){
		if (x%i == 0){
			printf("不是素数\n");
			return 0;
		}
	}
	printf("是素数\n");
	return 1;
}
int main(){
	int i = 0;
	printf("请输入一个数字：");
	scanf("%d", &i);
	sushu(i);
	system("pause");
	return 0;
}