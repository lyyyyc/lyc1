#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int sushu(int x){
	if (x <= 1){
		printf("��������\n");
		return 0;
	}
	for (int i = 2; i < x; ++i){
		if (x%i == 0){
			printf("��������\n");
			return 0;
		}
	}
	printf("������\n");
	return 1;
}
int main(){
	int i = 0;
	printf("������һ�����֣�");
	scanf("%d", &i);
	sushu(i);
	system("pause");
	return 0;
}