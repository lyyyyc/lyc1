#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

	//菜单
int Menu(){
	printf("------------------------\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("------------------------\n");
	printf("请输入选项：");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}
#define MAX_ROW 3
#define MAX_COL 3
	//棋盘
char board[MAX_ROW][MAX_COL];
void Init(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			board[row][col] = ' ';
		}
	}
	srand((unsigned int)time(0));//建立随机种子
}
void print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("| %c | %c | %c |\n", board[row][0], board[row][1], board[row][2]);
		printf("|---|---|---|\n");
	}
	//system("pause");//调试用
}
	//玩家
void playermove(){
	printf("玩家落子\n");
	while (1){
		printf("请输入坐标(row col)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0 || row >= MAX_ROW || col<0 || col >= MAX_COL){
			printf("非法坐标,请重新输入\n");
			continue;
		}
		if (board[row][col] != ' '){
			printf("位置重复，请重新输入\n");
			continue;
		}
		board[row][col] = 'x';
		break;
	}
	printf("落子完毕\n");
}
	//电脑
void computermove(){
	printf("电脑落子\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (board[row][col] != ' '){
			continue;
		}
		board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕\n");
}
	//检测
int full(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
char check(){
	for (int row = 0; row < MAX_ROW; ++row){
		if (board[row][0] == board[row][1] && board[row][0] == board[row][2])
			return board[row][0];
	}
	for (int col = 0; col < MAX_COL; ++col){
		if (board[0][col] == board[1][col] && board[0][col] == board[2][col])
			return board[0][col];
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
		return board[0][2];
	}
	if (full()){
		return 'q';
	}
	return ' ';
}
	//游戏
void Game(){
	Init();
	char winner = ' ';
	while (1){
		print();
		playermove();
		winner = check();
		if (winner != ' '){
			break;
		}
		computermove();
		winner = check();
		if (winner != ' '){
			break;
		}

	}
	if (winner == 'x'){
		printf("你赢了\n");
	}
	else if (winner == 'o'){
		printf("垃圾\n");
	}
	else if (winner == 'q'){
		printf("平局\n");
	}
	else{
		printf("bug\n");
	}
}
int main(){
	while (1){
		int choose = Menu();
		if (choose == 1){
			Game();
		}
		else if (choose == 0){
			printf("再见\n");
			break;
		}
		else{
			printf("输入有误\n");
		}
	}
	system("pause");
	return 0;
}