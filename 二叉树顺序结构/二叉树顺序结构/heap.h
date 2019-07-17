#pragma once


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;


void HeapInit(Heap* hp, HPDataType* array, int n);
void HeapPush(Heap* hp, HPDataType data);
void HeapPop(Heap* hp);
HPDataType Heap(Heap* hp);
int HeapSize(Heap* hp);
int HeaEmpty(Heap* hp);
void HeapSort(Heap* hp);
void HeapDestory(Heap* hp);


void TestHeap();