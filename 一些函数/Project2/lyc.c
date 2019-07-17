#include<stdio.h>
#include<stdlib.h>
void swap(int* x, int* y){
	int tmp = *x;
	 *x = *y;
	 *y = tmp;
}
int divide(int x, int y,int* ok){
	if (y == 0){
		*ok = 0;
		return 0;
	}
	*ok = 1;
	return x / y;
}
//x是素数返回1,不是返回0
int sushu(int x){
	if (x <= 1){
		return 0;
	}
	for (int i = 2; i < x; ++i){
		if (x%i == 0){
			return 0;
		}
	}
	return 1;
}
int runnian(int x){
	//x是闰年返回1，不是返回0
	if (x % 4 == 0 && x % 100 != 0){
		return 1;
	}
	else if (x & 400 == 0){
		return 1;
	}
	return 0;
}
int erfenchazhao(int arr[],int size,int find){
	int left = 0;
	int right = size - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (find <arr[mid]){
			right = mid - 1;
		}
		else if (find>arr[mid]){
			left = mid + 1;
		}
		else{
			return 1;
		}
	}
	return 0;
}
void plus(int* x){
	*x += 1;
}
int main(){
	int x=0;
	plus(&x);
	plus(&x);
	plus(&x);
	plus(&x);

	printf("%d\n",x);
	system("pause");
	return 0;
}
