#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch = 0;
	printf("������һ���ַ�:\n");
	while ((ch = getchar()) != EOF)//�Ӽ����л�ȡһ���ַ�����ASCII����ֵ����ch��ch��=��-1���ɽ���whileѭ��
	{
		if (ch >= 'a'&&ch <= 'z')//ch��97��122֮�䣬Ҳ����˵�������Сд��ĸ
		{
			printf("%c\n", ch - 32);//Сд��ĸ��ASCII����ֵ=��д��ĸ��ASCII����ֵ+32
		}
		else if (ch >= 'A'&&ch <= 'Z')//ch��65��90֮�䣬Ҳ����˵������Ǵ�д��ĸ
		{
			printf("%c\n", ch + 32);
		}	
	}
	system("pause");
	return 0;
}