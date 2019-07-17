#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	int j;
	for (i = 1; i <8; ++i){
		for (j = 2 * i - 1; j>0; --j){
			printf("*");
		}
		printf("\n");
	}
	int k;
	for (k = i - 2; k > 0; --k){
		for (j = 2 * k - 1; j > 0; --j){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}