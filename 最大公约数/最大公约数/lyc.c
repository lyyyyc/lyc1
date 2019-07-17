#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j;
	//int i = 0;
	int k ;
	int p;
	printf("请输入两个数；");
	scanf("%d %d", &i, &j);
	for (k=1; k <= i&&k<=j; ++k){
		if (i%k == 0 &&j%k == 0){
			p = k;
		}
	}
	printf("%d\n", p);
	system("pause");
	return 0;
}