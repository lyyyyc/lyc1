#include<stdio.h>
#include<stdlib.h>

int main(){
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6,7,8,9,10 };
	int tmp;
	int i = 0;
	for (i=0; i < sizeof(arr1) / sizeof(arr1[0]
		); ++i){
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	for (i=0; i < sizeof(arr1) / sizeof(arr1[0]
		); ++i) {
		printf("%d", arr1[i]);
	}
		printf("\n");
	for (i=0; i < sizeof(arr1) / sizeof(arr1[0]
		); ++i) {
		printf("%d", arr2[i]);
	}
		printf("\n");
	system("pause");
	return 0;
}