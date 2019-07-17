#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factor(int n){
	int result = 1;
	for (int i = 1; i <= n; ++i){
		result *= i;
	}
	return result;
}
int main(){
	printf("%d\n",factor(5));
	system("pause");
	return 0;
}