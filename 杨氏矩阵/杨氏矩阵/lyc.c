#include<stdio.h>
#include<stdlib.h>
void find(int arr[3][3], int i, int row, int col) {
	int x =0;
	int y=col-1;
	while ((x < row) && (y >=0)) {
		if (arr[x][y] == i) {
			printf("找到了 \n位置在:%d %d\n", x, y);
			break;
		}
		else if(arr[x][y]<i) {
			++x;
		}
		else  {	
			--y;
		}
		if ((x > row) || (y < 0)) {
			printf("没找到\n");
		}
	}
}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9, };
	int i =3;
	find(arr, i, 3, 3);
	system("pause");
	return 0;
}