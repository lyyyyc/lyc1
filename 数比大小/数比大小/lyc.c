#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	//求十个整数中的最大值
	//	int i = 0;
	//	int arr[10] = { 1, 2, 3, 4, 5, 90, 7, 8, 9, 10 };
	//	for (i; i < 10; ++i){
	//		if (arr[i] <=arr[i + 1]){
	//			continue;
	//		}
	//		else{
	//			printf("%d\n", arr[i]);
	//			break;
	//		}
	//	}

	//将三个数从大到小输出
	int i, j, k;
	printf("请输入三个数：");
	scanf("%d %d %d", &i, &j, &k);
	if (i > j&&i > k){
		if (j > k){
			printf("%d %d %d\n", i, j, k);
		}
		else if (j < k){
			printf("%d %d %d\n", i, k,j);
		}
		else{
			printf("%d %d %d\n", i, j, k);
		}
	}
	else if (j > i&&j > k){
		if (i > k){
			printf("%d %d %d\n", j, i, k);
		}
		else if (j < k){
			printf("%d %d %d\n", j, k, i);
		}
		else{
			printf("%d %d %d\n", j, i, k);
		}
	}
	else if (k>i&&k > j){
		if (i > j){
			printf("%d %d %d\n", k,i,j);
		}
		else if (i < j){
			printf("%d %d %d\n", k,j,i);
		}
		else{
			printf("%d %d %d\n", k,i,j);
		}
	}
	else if (i==j&&i>k){
		printf("%d %d %d\n", i, j, k);
	}
	else if (j==k&&j > i){
		printf("%d %d %d\n", j, k,i);
	}
	else if (i==k&&i > j){
		printf("%d %d %d\n", i, k,j);
	}
	else{
		printf("%d %d %d\n", i, j, k);
	}
	system("pause");
	return 0;
}