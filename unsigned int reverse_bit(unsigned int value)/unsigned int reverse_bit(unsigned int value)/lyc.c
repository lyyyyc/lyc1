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
			ret += ((value >> i) & 1) << (31 - i);//ȡ�����λ�����Ƶ���Ӧλ��
		}
		return ret;
	}
}
int main()
{
	unsigned int num = 0;
	printf("������һ������");
	scanf_s("%d", &num);
	printf("��ת�����Ϊ��%u\n", reverse_bit(num));
	system("pause");
	return 0;
}
