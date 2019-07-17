#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 1;
	int j = 0;
	for (i; i < 101; ++i){
		if (i % 10 == 9){

			++j;
		}
		if (i / 10 == 9)
			++j;
	}
	printf("%d\n", j);
	system("pause");
	return 0;
}