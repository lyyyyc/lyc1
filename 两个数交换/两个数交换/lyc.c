#include<stdio.h>
#include<stdlib.h>

int main(){
	//有临时变量
	/*int i = 1;
	int j = 2;
	int k;
	k = i;
	i = j;
	j = k;
	printf("i=%d,j=%d\n", i, j);*/

	////无临时变量
	//int i = 1;
	//int j = 2;
	////用异或，不会出现越界
	//i = i^j;
	//j = i^j;
	//i = i^j;
	//printf("i=%d,j=%d", i,j);
	
	//数大时会出现越界
	int i = 1;
	int j = 2;
	printf("i=%d,j=%d\n", i + j - i, j + i - j);
	system("pause");
	return 0;
}