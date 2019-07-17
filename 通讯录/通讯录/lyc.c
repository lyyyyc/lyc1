#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];
}PersonInfo;

#define MAX_PERSON_INFO_SIZE 300

typedef struct AddressBook
{
	PersonInfo persons[MAX_PERSON_INFO_SIZE];
	int size;
}AddressBook;

AddressBook g_address_book;//定义全局变量

void Menu()
{
	printf("===========\n");
	printf("1.新增\n");
	printf("2.删除\n");
	printf("3.查找\n");
	printf("4.修改\n");
	printf("5.打印\n");
	printf("6.排序\n");
	printf("7.清空\n");
	printf("0.推出\n");
	printf("===========\n");
	printf("请选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Empty()//空函数
{
}

void AddPersonInfo()
{
	printf("新增\n");
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE)
	{
		printf("内存已满，失败\n");
		return;
	}
	PersonInfo* Person_Info = &g_address_book.persons[g_address_book.size];
	printf("输入姓名：");
	scanf("%s",Person_Info->name);
	printf("输入电话：");
	scanf("%s", Person_Info->phone);
	++g_address_book.size;
	printf("成功\n");
}

void DelPersonInfo()
{

}

void FindPersonInfo()
{

}

void UpdatePersonInfo()
{

}

void PrintAllPersonInfo()
{
	printf("打印所有联系人\n");
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n",i, info->name, info->phone);
	}
	printf("共打印了%d条数据\n",g_address_book.size);
	printf("打印成功\n");
}

void SortPersonInfo()
{

}

void ClearAllPersonInfo()
{

}

typedef void(*Func)();

void Init()
{
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i)
	{
		g_address_book.persons[i].name[0] = '/0';
		g_address_book.persons[i].phone[0] = '/0';
	}
}

int main()
{
	Func arr[] = {
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatePersonInfo,
		SortPersonInfo,
		PrintAllPersonInfo,
		ClearAllPersonInfo
	};
	Init();
	while (1)
	{
		int choice = menu();
		if (choice < 0 || choice>sizeof(arr)/size(arr[0]))
		{
			printf("输入有误\n");
			continue;
		}
		if (choice == 0)
		{
			printf("再见\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}