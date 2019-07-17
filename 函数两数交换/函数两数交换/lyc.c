#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void jiaohuan(int* x, int* y){
	int tmp;
	tmp = *x;
	*x =*y;
	*y = tmp;

}
int main(){
	int i=2 ;
	int j=5 ;
	jiaohuan(&i,& j);
	printf("%d %d\n", i, j);
	system("pause");
	return 0;
}