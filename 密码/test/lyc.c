#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

int main(){
	
	char psw[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; ++i){
		printf("���룺");
		scanf("%s", psw);
		if (strcmp(psw, "123456") == 0){
			break;
		}
	}
	if (i < 3){
		printf("�ɹ�\n");
	}
	else {
		printf("3��ʧ��\n");
	}
	system("pause");
	return 0;
}