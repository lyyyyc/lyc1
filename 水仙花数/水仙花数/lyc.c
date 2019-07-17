#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	for (i = 100; i < 1000; ++i){
		int j = i % 10;
		int k = i / 10 % 10;
		int l = i / 100 % 10;
		if (j*j*j + k*k*k + l*l*l == i){
			printf("%d^3+%d^3+%d^3=%d\n",l,k,j, i);
		}
	}
	system("pause");
	return 0;
}