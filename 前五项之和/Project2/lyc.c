#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 0;
	int a=0;
	int Sn=0;
	int num = 0;
	scanf("%d", &num);
	for (i = 0; i < 5; ++i){
		a = a * 10 + num;
		Sn += a;
	}
	printf("%d\n", Sn);

	system("pause");
	return 0;
}