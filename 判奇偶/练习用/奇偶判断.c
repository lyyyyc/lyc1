#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i=0;
	printf("����һ����:");
	scanf("%d", &i);
	if (i % 2 == 0){
		printf("ż��\n");
	}
	else{
		printf("����\n");
	}
	system("pause");
	return 0;
}

