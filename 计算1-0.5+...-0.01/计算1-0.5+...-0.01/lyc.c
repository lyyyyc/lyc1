#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 1;
	double k=0;
	for (i; i < 101; ++i){
		if (i % 2 == 1){
			k += 1, 0 / i;
		}
		else{
			k -= 1.0 / i;
		}
	}
	printf("%g\n", k);
	system("pause");
	return 0;
}