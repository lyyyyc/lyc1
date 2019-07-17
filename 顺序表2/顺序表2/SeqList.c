#include"SeqList.h" 
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


void SeqListInit(PSeq ps, int capacity)
{
	ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);//����ռ�
		//malloc����Ϊvoid*��ʹ����Ҫǿ��ת��
	if (NULL == ps->_array)//��Ҫ�п�
	{
		assert(0);//������ʱ���ã�debug�汾��
		return;
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

void SeqListPushBack(PSeq ps, DataType data)//β��
{
#if 0
	assert(ps);
	//˳�����
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
#endif
	SeqListInsert(ps, ps->_size, data);
}

void SeqListPopBack(PSeq ps)//βɾ
{
#if 0
	assert(ps);
	if (SeqListEmpty(ps)) 
	{
		return;
	}
	ps->_size--;
#endif
	SeqListErase(ps, ps->_size - 1);
}

void SeqListPushFront(PSeq ps, DataType data)//ͷ��
{
#if 0
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i > 0; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
#endif
	SeqListInsert(ps, 0 ,data);
}

void SeqListPopFront(PSeq ps)//ͷɾ
{
#if 0
	if (SeqListEmpty(ps))
	{
		return;
	}
	for (int i = 1; i < ps->_size; ++i)
	{
		ps->_array[i-1]=ps->_array[i];
	}
#endif
	SeqListErase(ps, 0);
}

int SeqListEmpty(PSeq ps)
{
	assert(ps);
	return 0 == ps->_size;
}

void SeqListInsert(PSeq ps, int pos, DataType data)//����λ�ò�
{
	assert(ps);
	if (pos<0 || pos>ps->_size)
	{
		return;
	}
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeq ps, int pos)//����λ��ɾ
{
	assert(ps);
	if (pos<0||pos>ps->_size)
	{
		return;
	}
	for (int i = pos+1; i <ps->_size ; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	ps->_size--;
}

int SeqListFind(PSeq ps, DataType data)//����
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if(ps->_array[i]==data)
		{ 
			return i;
		}
	}
	return -1;
}

int SeqListSize(PSeq ps)//Ԫ�ظ���
{
	assert(ps);
	return ps->_size;
}

int SeqListCapacity(PSeq ps)//������С
{
	assert(ps);
	return ps->_capacity;
}

void SeqListClear(PSeq ps)//���
{
	assert(ps);
	ps->_size = 0;
}

void SeqListRemove(PSeq ps, DataType data)//�Ƴ���һ��ֵΪdata��Ԫ��
{
	SeqListErase(ps, SeqListFind(ps, data));
}

void SeqListRemoveAll(PSeq ps, DataType data)//�Ƴ�����ֵΪdata��Ԫ��
{
	assert(ps);
#if 0
	int pos = -1;
	while (-1!=(pos = SeqListFind(ps, data)))
	{
		SeqListErase(ps, pos);
	}
#endif
	int count=0;
	for (int i = 0; i < ps->_size;++i)
	{
		if (data == ps->_array[i])
		{
			count++;
		}
		else
		{
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	* pRight = temp;
}

void SeqListBubbleSort(PSeq ps)//ð������
{
	for (int i = 0; i < ps->_size - 1; ++i)//����ð���ܵ�����
	{
		int Ischange = 0;
		for (int j = 0; j < ps->_size-1; ++j)
		{
			if (ps->_array[j] > ps->_array[j + 1])
			{
				Ischange = 1;
				Swap(&ps->_array[j], &ps->_array[j + 1]);
			}
		}
	}
}

/*int SeqListBinaryFind(PSeq ps, DataType data)//���ֲ���
{
	assert(ps);
	int left = 0;
	int right = ps->_size - 1;
	int mid = (ps->_size - 1) >> 1;
	while (left < right)
	{
		if (data > ps->_array[mid])
		{
			left = mid + 1;
		}
		else if (data < ps->_array[mid])
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}*/

void CheckCapacity(PSeq ps)//�������
{
	assert(ps);
	if(ps->_size == ps->_capacity)//�ռ䲻����
	{
		int newCapacity = ps->_capacity * 2;
		//�����¿ռ�
		int* pTemp = (DataType*)malloc(newCapacity * sizeof(DataType));
		if (pTemp == NULL)
		{
			assert(0);
			return;
		}
		//realloc(p,size)
		//����Ԫ��
		for(int i=0;i<ps->_size;++i)
		{
			pTemp[i] = ps->_array[i];
		}
		//�ͷžɿռ�
		free(ps->_array);
		//����
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

void SeqListPrint(PSeq ps)//��ӡ˳���
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListDestroy(PSeq ps)//����
{
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void 	TestSeqList()
{
	SeqList s;
	int pos = -1;
	SeqListInit(&s,10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 0);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);
	SeqListPushBack(&s, 9); 
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 1, 5);
	SeqListPrint(&s);
	pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		printf("5 is in %d\n", pos);
	}
	else
	{
		printf("5 is not in %d\n", pos);
	}
	SeqListErase(&s, 1);
	pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		printf("5 is in %d\n", pos);
	}
	else
	{
		printf("5 is not in %d\n", pos);
	}
	SeqListPrint(&s);
	printf("size=%d\n", SeqListSize(&s));
	printf("capacity=%d\n", SeqListCapacity(&s));
	SeqListDestroy(&s);
}
