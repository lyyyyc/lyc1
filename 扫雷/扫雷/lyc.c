#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10 
int menu(){
	printf("-----------------------\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("-----------------------\n");
	printf("请输入选项：\n");
	int choose=0 ;
	scanf("%d", &choose);
	return choose;
}
void Init(char map1[MAX_ROW][MAX_COL], char map2[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			map1[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			map2[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (map2[row][col] == '1'){
			continue;
		}
		map2[row][col] = '1';
		--n;
	}
}
void printmap(char map[MAX_ROW][MAX_COL]){
	printf("      ");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL-1; ++col){
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf("  %d|  ",row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void updatemap1(int row,int col ,
	char map1[MAX_ROW][MAX_COL],
	char map2[MAX_ROW][MAX_COL]){
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 &&
		row-1<MAX_ROW&&col-1<MAX_COL&&
		map2[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0 && col  >= 0 &&
		row - 1<MAX_ROW&&col <MAX_COL&&
		map2[row - 1][col ] == '1'){
		++count;
	}if (row - 1 >= 0 && col + 1 >= 0 &&
		row - 1<MAX_ROW&&col+1<MAX_COL&&
		map2[row - 1][col +1] == '1'){
		++count;
	}if (row  >= 0 && col - 1 >= 0 &&
		row <MAX_ROW&&col - 1<MAX_COL&&
		map2[row ][col - 1] == '1'){
		++count;
	}if (row>= 0 && col + 1 >= 0 &&
		row <MAX_ROW&&col + 1<MAX_COL&&
		map2[row ][col + 1] == '1'){
		++count;
	}if (row + 1 >= 0 && col - 1 >= 0 &&
		row +1<MAX_ROW&&col - 1<MAX_COL&&
		map2[row + 1][col - 1] == '1'){
		++count;
	}if (row+ 1 >= 0 && col  >= 0 &&
		row + 1<MAX_ROW&&col <MAX_COL&&
		map2[row + 1][col] == '1'){
		++count;
	}if (row +1 >= 0 && col + 1 >= 0 &&
		row +1<MAX_ROW&&col + 1<MAX_COL&&
		map2[row + 1][col + 1] == '1'){
		++count;
	}
	map1[row][col] = '0' + count;
}
void game(){
	//map1:游戏图；map2：地雷图
	char map1[MAX_ROW][MAX_COL];
	char map2[MAX_ROW][MAX_COL];
	int blank_count_already_show = 0;
	Init(map1, map2);
	while (1){
		printmap(map1);
		printmap(map2);//调试用
		printf("请输入一组坐标（row col）：");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("非法输入，请重新输入：\n");
			continue;
		}
		if (map1[row][col] != '*'){
			printf("此位置已翻开\n");
			continue;
		}
		if (map2[row][col] == '1'){
			printf("游戏结束\n");
			printmap(map2);
			break;
		}
		++blank_count_already_show;
		if (blank_count_already_show == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("游戏胜利\n");
			printmap(map2);
			break;
		}
		updatemap1(row, col, map1, map2);
	}
}
int main() {
	while (1){
		int choose = menu();
		if (choose == 1){
			game();
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