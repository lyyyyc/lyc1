#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int runnian(int n){
	if (n % 4 == 0 && n % 100 != 0){
		printf("����ͨ����\n");
		return 1;
	}
	else if (n % 400 == 0){
		printf("����������\n");
		return 1;
	}
	else{
		printf("��������\n");
		return 0;
	}
}
int main(){
	int i = 0;
	printf("������һ����ݣ�");
	scanf("%d", &i);
	runnian(i);
	system("pause");
	return 0;
}