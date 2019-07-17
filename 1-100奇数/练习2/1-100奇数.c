#include<stdio.h>
#include<stdlib.h>

int main(){
	for (int i = 0; i < 101; ++i){
		if (i % 2 == 1){
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
