#include<stdio.h>
#include<stdlib.h>

int main1(){
	int i = 1;
	for (i; i < 101; i += 2){
		int j = 1 / i;
		int sum=0;
		sum +=j;
		printf("g\n", sum);
	}
	system("pause");
	return 0;
}