#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n){
	if (n <= 0){
		return 0;
	}
	else if (n>0 && n < 10){
		return n;
	}
	else{
		return DigitSum(n / 10) + n % 10;
	}
}
int main(){
	int i = 111;
	printf("%d\n", DigitSum(i));
	system("pause");
	return 0;
}