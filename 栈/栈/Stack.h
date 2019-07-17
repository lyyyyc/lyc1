#pragma once
typedef int STDataType;
typedef struct Stack 
{
	STDataType* _array;
	int _Top;
	int _capacity;
	int _size;
}Stack;
void StackInit(Stack* ps, STDataType capacity);
void StackPush(Stack* ps,STDataType data);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
int StackCapacity(Stack* ps);
void CheckCapacity(Stack* ps);
void StackPrint(Stack* ps);
void StackDestory(Stack* ps);
void TestStack();