#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	int j;
	int a[10][10];
	a[0][0] = 1;   //��һ�У���һ��Ϊ1.
	for (i = 0; i < 10; ++i)
	{
		a[i][0] = 1;
		for (j = 0; j <= i; ++j)
		{
			if (j == 0)  //�ж��Ƿ�Ϊ��һ�У����������Ϊ1
				a[i][j] = a[0][0];
			else if (i >= 1 && j >= 1 && i != j)  //�ж��Ƿ�Ϊ�м䣬���ǵ�һ�У�Ҳ�������һ�У�
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			else  if (j == i) //���ж��Ƿ�Ϊ���һ��
				a[i][j] = a[i - 1][j - 1];
		}
	}
	for (i = 0; i < 10; i++)   //����������
	{
		for (j = 0; j <= i; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}