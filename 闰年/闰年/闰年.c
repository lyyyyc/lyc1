#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 1000;
	printf("�������:");
	scanf("%d", &i);
	for (i; i < 2001; ++i){
		if (i % 4 == 0 && i % 100 != 0){
			printf("������\n");
			break;
		}
		else if (i % 400 == 0){
			printf("������\n");
			break;
		}
		else if (i<1000 || i>2000){
			printf("��������\n");
			break;
		}
		else{
			printf("��������\n");
			break;
		}
	}

	system("pause");
	return 0;
}