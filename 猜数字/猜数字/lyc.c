#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(){
	printf("==================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("==================\n");
	printf("������ѡ�");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int to_guess = rand() % 100 + 1;
	while(1){
		printf("������һ������:");
		int num = 0;
		scanf("%d", &num);
		if (num < to_guess){
			printf("����\n");
		}
		else if (num>to_guess){
			printf("����\n");
		}
		else{
			printf("�¶���\n");
			break;
		}
	}
}
int main(){
	//ʱ���
	//time����ֵ������time_t�з��ŵ�64λ����
	//srand����unsigned int 32λ�޷�������
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("bye\n");
			break;
		}
		else{
			printf("��������\n");
		}
	}
	system("pause");
	return 0;
}