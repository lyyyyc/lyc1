#include<stdio.h>
#include<stdlib.h>

int main(){
	//����ʱ����
	/*int i = 1;
	int j = 2;
	int k;
	k = i;
	i = j;
	j = k;
	printf("i=%d,j=%d\n", i, j);*/

	////����ʱ����
	//int i = 1;
	//int j = 2;
	////����򣬲������Խ��
	//i = i^j;
	//j = i^j;
	//i = i^j;
	//printf("i=%d,j=%d", i,j);
	
	//����ʱ�����Խ��
	int i = 1;
	int j = 2;
	printf("i=%d,j=%d\n", i + j - i, j + i - j);
	system("pause");
	return 0;
}