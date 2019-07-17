#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 0
//打印100~200 之间的素数
int main()
{
	int i = 100;
	int j = 0;
	int count = 0;
	for (i; i <= 200; ++i)
	{
		int j = 2;
		count = 0;//每选一个数就将count置0
		for (j; j < i; ++j)
		{
			if (i % j == 0)
			{
				count = 1;//不是素数则count置1
			}
		}
		if (count == 0)//count为0则输出i
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
#endif

#if 0
//输出乘法口诀表
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
//判断1000年---2000年之间的闰年
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
//给定两个整形变量的值，将两个值的内容进行交换。
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
//不允许创建临时变量，交换两个数的内容
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
//求10 个整数中最大值。
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
//将三个数按从大到小输出。
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

//求两个数的最大公约数。
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