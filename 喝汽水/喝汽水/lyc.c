#include<stdio.h>
#include<stdlib.h>

int main() {
	int money = 20;
	int total=20;
	int empty=20;
	while (empty >= 2) {
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("�ܺ�%dƿ\n", total);
	system("pause");
	return 0;
}	