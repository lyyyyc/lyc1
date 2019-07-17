#include"Stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (STDataType*)malloc(sizeof(STDataType)*3);
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_size = 0;
}
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if(StackEmpty(ps))
	{
		return;
	}
	ps->_size--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;
}
int StackCapacity(Stack* ps)
{
	assert(ps);
	return ps->_capacity;
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		int newCapacity = ps->_capacity * 2;
		STDataType* temp = (STDataType*)malloc(sizeof(STDataType)*newCapacity);
		if (temp == NULL)
		{
			assert(0);
			return ;
		}
		for (int i = 0; i < ps->_size; ++i)
		{
			temp[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = temp;
		ps->_capacity = newCapacity;
	}
}
void StackPrint(Stack* ps)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s,1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPrint(&s);
	StackPop(&s);
	StackPrint(&s);
	printf("top=%d\n", StackTop(&s));
	printf("size=%d\n", StackSize(&s));
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	StackPrint(&s);
	printf("size=%d\n", StackSize(&s));
	printf("capacity=%d\n", StackCapacity(&s));
	StackDestory(&s);
	printf("size=%d\n", StackSize(&s));
	printf("capacity=%d\n", StackCapacity(&s));
}