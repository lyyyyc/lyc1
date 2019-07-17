#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int to_find = 0;
	printf("请输入一个数字：\n");
	scanf("%d", &to_find);
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] < to_find){
			left = mid + 1;
		}
		else if (arr[mid] > to_find){
			right = mid - 1;
		}
		else{
			//printf("找到了\n");
			break;
		}
	}
	if (left <= right){
		printf("找到了\n");
	}
	else{
		printf("没找到\n");
	}
	system("pause");
	return 0;
}

int BinarySearch(int* a, int n, int x) {
	assert(a);
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int mid = left + ((left + right) >> 1);
		if (a[mid] < x) {
			left = mid + 1;
		}
		else if (a[mid] > x) {
			right = mid;
		}
		else {
			return mid;
		}
	}
	return -1;
}
