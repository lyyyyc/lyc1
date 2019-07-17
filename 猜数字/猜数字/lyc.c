#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(){
	printf("==================\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("==================\n");
	printf("请输入选项：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void game(){
	int to_guess = rand() % 100 + 1;
	while(1){
		printf("请输入一个数字:");
		int num = 0;
		scanf("%d", &num);
		if (num < to_guess){
			printf("低了\n");
		}
		else if (num>to_guess){
			printf("高了\n");
		}
		else{
			printf("猜对了\n");
			break;
		}
	}
}
int main(){
	//时间戳
	//time返回值类型是time_t有符号的64位整数
	//srand参数unsigned int 32位无符号整数
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
			printf("输入有误\n");
		}
	}
	system("pause");
	return 0;
}