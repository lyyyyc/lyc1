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

AddressBook g_address_book;//����ȫ�ֱ���

void Menu()
{
	printf("===========\n");
	printf("1.����\n");
	printf("2.ɾ��\n");
	printf("3.����\n");
	printf("4.�޸�\n");
	printf("5.��ӡ\n");
	printf("6.����\n");
	printf("7.���\n");
	printf("0.�Ƴ�\n");
	printf("===========\n");
	printf("��ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Empty()//�պ���
{
}

void AddPersonInfo()
{
	printf("����\n");
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE)
	{
		printf("�ڴ�������ʧ��\n");
		return;
	}
	PersonInfo* Person_Info = &g_address_book.persons[g_address_book.size];
	printf("����������");
	scanf("%s",Person_Info->name);
	printf("����绰��");
	scanf("%s", Person_Info->phone);
	++g_address_book.size;
	printf("�ɹ�\n");
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
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n",i, info->name, info->phone);
	}
	printf("����ӡ��%d������\n",g_address_book.size);
	printf("��ӡ�ɹ�\n");
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
			printf("��������\n");
			continue;
		}
		if (choice == 0)
		{
			printf("�ټ�\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}