#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int runnian(int n){
	if (n % 4 == 0 && n % 100 != 0){
		printf("是普通闰年\n");
		return 1;
	}
	else if (n % 400 == 0){
		printf("是世纪闰年\n");
		return 1;
	}
	else{
		printf("不是闰年\n");
		return 0;
	}
}
int main(){
	int i = 0;
	printf("请输入一个年份：");
	scanf("%d", &i);
	runnian(i);
	system("pause");
	return 0;
}