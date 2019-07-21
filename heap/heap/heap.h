#pragma once


typedef int HPDataType;

//�������ѽ��и��죬ʹ�û����Կ��ƴ�����ѻ���С��
typedef int (*PCOM)(HPDataType, HPDataType);

// ����Ԫ�ؽ���С�ڱȽ� 
int Less(HPDataType left, HPDataType right);

// ����Ԫ�ؽ��д��ڱȽ� 
int Greater(HPDataType left, HPDataType right);

typedef struct
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PCOM Compare; // ����ָ������������û����ݵıȽ��ж���Ԫ�ط��� 
}Heap;

void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);
void DestroyHeap(Heap* hp);



