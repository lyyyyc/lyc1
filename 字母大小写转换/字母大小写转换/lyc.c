#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch = 0;
	printf("请输入一个字符:\n");
	while ((ch = getchar()) != EOF)//从键盘中获取一个字符，其ASCII代码值赋给ch且ch！=（-1）可进行while循环
	{
		if (ch >= 'a'&&ch <= 'z')//ch在97到122之间，也就是说输入的是小写字母
		{
			printf("%c\n", ch - 32);//小写字母的ASCII代码值=大写字母的ASCII代码值+32
		}
		else if (ch >= 'A'&&ch <= 'Z')//ch在65到90之间，也就是说输入的是大写字母
		{
			printf("%c\n", ch + 32);
		}	
	}
	system("pause");
	return 0;
}