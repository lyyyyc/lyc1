#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,3,3,1,4,6,4,5,5 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	/*�ҳ������������ͽ������е�ÿ����ȫ��ȡ������㣬
	�磺arr[1]={1,3,3,1,4}
	01^11=10������������10^11=01,01^01=00,000^100=100=4
   �����������Ϊ1
	��1��a=a^b    c^a�൱��c^(a^b)
	��2���Լ�����Լ������൱��û����򣬻����Լ���*/
	for (i = 1; i < len; i++)
	{
		arr[0] = arr[0] ^ arr[i];
	}
	printf("����������:%d", arr[0]);
	system("pause");
	return 0;
}
