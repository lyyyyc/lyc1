#include<stdio.h>
#include<stdlib.h>

//µÝ¹é
int fib(int x){
	if (x <= 2){
		return 1;
	}
	return fib(x-1)+fib(x-2);
}
int fib2(int x,int last1,int last2){
	if (x <= 2){
		return 1;
	}
	return fib2(x - 1, last1, last1 + last2);
}
//·ÇµÝ¹é
int fin3(int x){
	if (x <= 2){
		return 1;
	}
	int last1 = 1;
	int last2 = 1;
	int cur = 0;
	for (int i = 3; i <= x; ++i){
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main(){
	printf("ret=%d\n", fib(50));
	system("pause");
	return 0;
}