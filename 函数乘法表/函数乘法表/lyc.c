#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int mul(int n){
	int x = 0;
	int y = 0;
	for (x=1; x <=n; ++x){
		for (y=1; y <= x; ++y){
			int z = x*y;
			printf("%d*%d=%d\t", x, y, z);
		}
		printf("\n");
	}
}
int main(){
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	mul(n);
	system("pause");
	return 0;
}