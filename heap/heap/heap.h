#pragma once


typedef int HPDataType;

//对上述堆进行改造，使用户可以控制创建大堆还是小堆
typedef int (*PCOM)(HPDataType, HPDataType);

// 堆中元素进行小于比较 
int Less(HPDataType left, HPDataType right);

// 堆中元素进行大于比较 
int Greater(HPDataType left, HPDataType right);

typedef struct
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PCOM Compare; // 函数指针变量，保存用户传递的比较中堆中元素方法 
}Heap;

void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);
void DestroyHeap(Heap* hp);



