#include<stdio.h>
#include<stdlib.h>
void init(int str[],int size){
	for (int i = 0; i < size; ++i){
		str[i] = i;
	}
}
void empty(int str[],int size){
	for (int i = 0; i < size; ++i){
		str[i] = 0;
	}
}
void reverse(int str[], int size){
	int left = 0;
	int right = size - 1;
	while (left < right){
		int tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		++left;
		--right;
	}
}
void print(int str[],int size){
	for (int i = 0; i < size; ++i){
		printf("%d", str[i]);
	}
	printf("\n");
}
int main(){
	int arr[5];
	int s = sizeof(arr) / sizeof(arr[0]);
	init(arr,s);
	empty(arr,s);
	reverse(arr, s);
	print(arr, s);
	system("pause");
	return 0;
}