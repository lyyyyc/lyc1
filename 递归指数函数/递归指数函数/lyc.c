#include<stdio.h>
#include<stdlib.h>

int mul(int n, int k){
	if (k == 0){
		return 0;
	}
	else if (k == 1){
		return n;
	}
	return n*mul(n, k - 1);
}
int main(){
	int i = 3;
	int j = 3;
	printf("%d\n", mul(i, j));
	system("pause");
	return 0;
}