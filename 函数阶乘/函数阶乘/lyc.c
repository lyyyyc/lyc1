#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�ݹ�
int jiecheng(int x){
	if (x <= 1){
		return 1;
	}
	else{
		return x*jiecheng(x - 1);
	}
}
//�ǵݹ�
int jiecheng(int x){
	int y = 1;
	int z = 1;
	for (z; z <= x; ++z){
		y *= z;
	}
	return y;
}
int main(){
	int i = 0;
	printf("������һ�����֣�");
	scanf("%d", &i);
	printf("%d\n", jiecheng(i));
	system("pause");
	return 0;
}