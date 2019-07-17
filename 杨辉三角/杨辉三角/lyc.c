#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	int j;
	int a[10][10];
	a[0][0] = 1;   //第一行，第一列为1.
	for (i = 0; i < 10; ++i)
	{
		a[i][0] = 1;
		for (j = 0; j <= i; ++j)
		{
			if (j == 0)  //判断是否为第一列，如果是设置为1
				a[i][j] = a[0][0];
			else if (i >= 1 && j >= 1 && i != j)  //判断是否为中间，不是第一列，也不是最后一列，
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			else  if (j == i) //；判断是否为最后一列
				a[i][j] = a[i - 1][j - 1];
		}
	}
	for (i = 0; i < 10; i++)   //输出杨辉三角
	{
		for (j = 0; j <= i; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}