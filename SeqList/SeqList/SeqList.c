#include"SeqList.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SLDataType*)malloc(sizeof(SLDataType) * capacity);
	if (psl->array == NULL)
	{
		assert(0);
		return;
	}
	psl->capacity = capacity;
	psl->size = 0;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if(psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity * 2;
		int* pTem = (SLDataType*)malloc(newcapacity * sizeof(SLDataType));
		for (int i = 0; i < psl->size; ++i)
		{
			pTem[i] = psl->array[i];
		}
		free(psl->array);
		psl->array = pTem;
		psl->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType data)
{
	assert(psl);

	CheckCapacity(psl);
	psl->array[psl->size] = data;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	if (SeqListEmpty(psl))
	{
		return;
	}
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType data)
{
	assert(psl);
	CheckCapacity(psl);
	for (int i = psl->size - 1; i > 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = data;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	if (SeqListEmpty(psl))
	{
		return;
	}
	for (int i = 0; i < psl->size; ++i)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
SLDataType SeqListFind(SeqList* psl, SLDataType data);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType data);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType data);
void  SeqListClear(SeqList* psl);
SLDataType SeqListEmpty(SeqList* psl);
SLDataType SeqListSize(SeqList* psl);
SLDataType SeqListCapacity(SeqList* psl);
void SeqListDestory(SeqList* psl);

void Test();