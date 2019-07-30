#pragma once
#include<stdio.h>
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* psl, size_t capacity);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType data);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType data);
void SeqListPopFront(SeqList* psl);
SLDataType SeqListFind(SeqList* psl, SLDataType data);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType data);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType data);
void SeqListAllRemove(SeqList* psl, SLDataType data);
void  SeqListClear(SeqList* psl);
SLDataType SeqListEmpty(SeqList* psl);
SLDataType SeqListSize(SeqList* psl);
SLDataType SeqListCapacity(SeqList* psl);
void SeqListPrint(SeqList* psl);
void SeqListDestory(SeqList* psl);

void Test();
