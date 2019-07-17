#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

	//�˵�
int Menu(){
	printf("------------------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("------------------------\n");
	printf("������ѡ�");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}
#define MAX_ROW 3
#define MAX_COL 3
	//����
char board[MAX_ROW][MAX_COL];
void Init(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			board[row][col] = ' ';
		}
	}
	srand((unsigned int)time(0));//�����������
}
void print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("| %c | %c | %c |\n", board[row][0], board[row][1], board[row][2]);
		printf("|---|---|---|\n");
	}
	//system("pause");//������
}
	//���
void playermove(){
	printf("�������\n");
	while (1){
		printf("����������(row col)\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0 || row >= MAX_ROW || col<0 || col >= MAX_COL){
			printf("�Ƿ�����,����������\n");
			continue;
		}
		if (board[row][col] != ' '){
			printf("λ���ظ�������������\n");
			continue;
		}
		board[row][col] = 'x';
		break;
	}
	printf("�������\n");
}
	//����
void computermove(){
	printf("��������\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (board[row][col] != ' '){
			continue;
		}
		board[row][col] = 'o';
		break;
	}
	printf("�����������\n");
}
	//���
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
	//��Ϸ
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
		printf("��Ӯ��\n");
	}
	else if (winner == 'o'){
		printf("����\n");
	}
	else if (winner == 'q'){
		printf("ƽ��\n");
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
			printf("�ټ�\n");
			break;
		}
		else{
			printf("��������\n");
		}
	}
	system("pause");
	return 0;
}