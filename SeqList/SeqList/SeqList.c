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
	for (int i = psl->size - 1; i >=0; i--)
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

SLDataType SeqListFind(SeqList* psl, SLDataType data)
{
	assert(psl);
	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType data)
{
	assert(psl);
	if (pos<0 || pos>psl->size)
	{
		return;
	}
	CheckCapacity(psl);
	for (int i = psl->size; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = data;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	if (pos<0 || pos>psl->size)
	{
		return;
	}
	for (int i = pos; i < psl->size; ++i)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType data)
{
	SeqListErase(psl, SeqListFind(psl, data));
}

void  SeqListClear(SeqList* psl)
{
	assert(psl);
	psl->size = 0;
}

SLDataType SeqListEmpty(SeqList* psl)
{
	assert(psl);
	return 0 == psl->size;
}

SLDataType SeqListSize(SeqList* psl)
{
	assert(psl);
	return psl->size;
}

SLDataType SeqListCapacity(SeqList* psl)
{
	assert(psl);
	return psl->capacity;
}

void SeqListPrint(SeqList* psl)
{
	for (int i = 0; i < psl->size; ++i)
		printf("%d ", psl->array[i]);
	printf("\n");
}

void SeqListDestory(SeqList* psl)
{
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
}

void Test()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	printf("size=%d\n", SeqListSize(&s));
	SeqListPrint(&s);

	SeqListPushFront(&s, 9);
	printf("size=%d\n", SeqListSize(&s));
	SeqListPrint(&s);

	SeqListPushFront(&s, 9);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopFront(&s);
	printf("size=%d\n", SeqListSize(&s));
	SeqListPrint(&s);

	SeqListFind(&s, 3);

	SeqListInsert(&s, 2, 3);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListPrint(&s);

	SeqListRemove(&s, 7);
	SeqListPrint(&s);

	SeqListClear(&s);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));

	SeqListDestory(&s);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
}