#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int avenue(int x, int y) {
	int i, j;
	i = x + y;
	j = i >> 1;
	printf("平均值是%d\n", j);
}
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	avenue(a, b);
	system("pause");
	return 0;
}