#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 0
//��ӡ100~200 ֮�������
int main()
{
	int i = 100;
	int j = 0;
	int count = 0;
	for (i; i <= 200; ++i)
	{
		int j = 2;
		count = 0;//ÿѡһ�����ͽ�count��0
		for (j; j < i; ++j)
		{
			if (i % j == 0)
			{
				count = 1;//����������count��1
			}
		}
		if (count == 0)//countΪ0�����i
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
#endif

#if 0
//����˷��ھ���
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i < 10; ++i)
	{
		for (j = 1; j < 10; ++j)
		{
			k = i * j;
			printf("%d*%d=%d\t", i, j, k);
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
//�ж�1000��---2000��֮�������
int main()
{
	int i = 0;
	for (i = 1000; i <= 2000; ++i)
	{
		if (i % 400 == 0)
		{
			printf("%d\n",i);
		}
		if ((i % 4 == 0) && (i % 100 != 0))
		{
			printf("%d\n",i);
		}

	}
	return 0;
}
#endif

#if 0
//�����������α�����ֵ��������ֵ�����ݽ��н�����
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 3;
	int tmp = i;
	i = j;
	j = tmp;
	printf("%d %d\n", i, j);
	return 0;
}
#endif

#if 0
//����������ʱ����������������������
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 2;
	i=i^ j;
	j = i^j;
	i = i ^ j;
	printf("i=%d j=%d\n", i, j);
	return 0;
}
#endif

#if 0
//��10 �����������ֵ��
int main()
{
	int a[10] = { 1,5,4,7,2,9,3,0,8,6 };
	int pos = a[0];
	int i = 0;
	for (i; i < 10; ++i)
	{
		if (pos >a[i ])
		{
			continue;
		}
		else
		{
			pos = a[i];
		}
	}
	printf("%d\n", pos);
	return 0;
}
#endif

#if 0
//�����������Ӵ�С�����
int main()
{
	int a, b, c, t;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
#endif

//�������������Լ����
int main()
{
	int i, j,k,t;
	scanf("%d %d", &i, &j);
	for (k = 1; k <= i && k <= j; ++k)
	{
		if ((i % k == 0) && (j % k) == 0)
		{
			t = k;
		}
	}
	printf("%d\n", t);
	return 0;
}