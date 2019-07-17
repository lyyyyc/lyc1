#include<stdio.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		unsigned int ret = 0;
		int i = 0;
		for (i = 0; i < 32; i++)
		{
			ret += ((value >> i) & 1) << (31 - i);//取出最低位，左移到相应位置
		}
		return ret;
	}
}
int main()
{
	unsigned int num = 0;
	printf("请输入一个数：");
	scanf_s("%d", &num);
	printf("翻转后的数为：%u\n", reverse_bit(num));
	system("pause");
	return 0;
}
