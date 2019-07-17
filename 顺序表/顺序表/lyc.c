
#include"SeqList.h"

#include<malloc.h>

#include<assert.h>

#include<stdio.h>







void SeqListInit(PSeq ps, int capacity) {

	//˳����ʼ��,������������ʼ����һ��˳���˳�������ٸ�Ԫ�أ�������

	//��������ռ�,sizeof��Ҫ�ֽ����������capacityԪ�أ�

	ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);

	//malloc����ֵΪvoid*�����з���ֵ����ǿת����ǰ�����DataType*

	//���ٳɹ������ؿռ��׵�ַ������ʧ�ܣ����ؿ�

	//mallocʹ�ý����п�

	if (NULL == ps->_array) {

		assert(0);//�������ʧ�ܣ�����ͣ�£�ֻ�ڵ��԰汾�����ã�release�汾�»ᱻ�Ż�



		return;

	}

	ps->_capacity = capacity;

	ps->_size = 0;

	return;

}



//˳��������

void SeqListDestroy(PSeq ps) {

	if (ps->_array) {

		free(ps->_array);//�ͷ�˳���ռ�

		ps->_array = NULL;//�ռ��ͷţ�ָ��Ϊ��

		ps->_capacity = 0;//����Ϊ0

		ps->_size = 0;//����Ԫ�ظ���Ϊ0

	}

}



//β��

void SqListDPushBack(PSeq ps, DataType data) {

	assert(ps);



	ps->_array[ps->_size] = data;//����Ԫ��.sizeҲ�ǽ���β�����һ��Ԫ����һ��λ��

	ps->_size++;



}

//βɾ

void SeqListDPopBack(PSeq ps) {

	assert(ps);//

	if (SeqLisrtEmpty(ps))

		return;

	ps->_size--;





}

//��̬˳����ͷ��

void SeqListDPushFront(PSeq ps, DataType data) {

	assert(ps);

	//CheakCapacity(ps);�ж�˳��������Ԫ��

	//��˳���������Ԫ��ͬ��������һ��λ��

	for (int i = ps->_size - 1; i >= 0; i--) {//i��ʾ���Ƶ�Ԫ��

		//for(int i=ps->_size;i>0;i--),�����size,��ʾԪ�ر����Ƶ���λ��

		ps->_array[i + 1] = ps->_array[i];

	}

	//����Ԫ��

	ps->_array[0] = data;

	++ps->_size;





}





//��̬˳����ͷɾ

void SeqListDPopFront(PSeq ps) {



	if (SeqLisrtEmpty(ps))

		return;

	for (int i = 1; i < ps->_size; ++i)

		ps->_array[i - 1] = ps->_array[i];



	ps->_size--;



}

//�п�



int SeqLisrtEmpty(PSeq ps) {

	assert(ps);

	return 0 == ps->_size;//˳���������ЧԪ��



}

//����λ�ò���

void SeqListInsert(PSeq ps, int pos, DataType data) {

	assert(ps);

	if (pos<0 || pos>ps->_size)

		return;

	//checkcapacity(ps);

	for (int i = ps->_size - 1; i >= pos; i--)

	{

		ps->_array[i + 1] = ps->_array[i];

		ps->_array[i] = data;

	}

	ps->_size++;



}









//����λ��ɾ��

void  SeqListErase(PSeq ps, int pos) {

	assert(ps);

	if (pos < 0 || pos >= ps->_size)

		//return;

	//����ǰλ��֮��Ԫ��������һ��Ԫ��

		for (int i = pos + 1; i < ps->_size; ++i);



}

//˳������ݲ���

int SeqLisrtFind(PSeq ps, DataType data) {



	assert(ps);

	for (int i = 0; i < ps->_size; i++) {

		if (ps->_array[i] == data)

			return i;

	}

	return -1;

}



//˳���Ԫ�ظ���

int SeqLisrtSize(PSeq ps) {

	assert(ps);

	return 0 == ps->_size;



}

//˳�������

int SeqLisrtCapacity(PSeq ps) {

	assert(ps);

	return ps->_capacity;

}



//˳������

void SeqLisrtClear(PSeq ps) {

	assert(ps);

	ps->_size = 0;



}



//�Ƴ���һ������������x

void SeqListRemove(PSeq ps, DataType data) {

	assert(ps->_array > 0);



	for (int i = 0; i < ps->_size; ++i)

	{

		if (ps->_array[i] == data)

		{

			for (int j = i + 1; j < ps->_size; ++j)

			{

				ps->_array[j - 1] = ps->_array[j];

			}

			ps->_size--;

		}

	}

}



void CheckCapacity(PSeq ps) {

	assert(ps);

	int newCapacity = ps->_capacity * 2;

	//�����¿ռ�

	int* pTemp = (DataType*)malloc(newCapacity * sizeof(DataType));

	if (NULL == pTemp) {

		assert(0);

		return;

	}

	//malloc(p,size)

	//����Ԫ��,

	for (int i = 0; i < ps->_size; ++i)

		pTemp[i] = ps->_array[i];

	//�ͷžɿռ�

	free(ps->_array);

	ps->_array = pTemp;

	ps->_capacity = newCapacity;



}





//��ӡ

void SeqListPrint(PSeq ps) {

	for (int i = 0; i < ps->_size; ++i)

		printf("%d", ps->_array[i]);

	printf("\n");

}





void TestSeqList() {

	SeqList s;

	SeqListInit(&s, 10);

	SqListDPushBack(&s, 1);

	SqListDPushBack(&s, 2);

	SqListDPushBack(&s, 3);

	SqListDPushBack(&s, 4);

	SqListDPushBack(&s, 5);



	SeqListPrint(&s);



	SeqListDPopBack(&s);

	SeqListPrint(&s);



	SeqListDPushFront(&s, 0);

	SeqListPrint(&s);



	SeqListDPopFront(&s);

	SeqListPrint(&s);



	SeqListInsert(&s, 1, 5);

	SeqListPrint(&s);

	int pos = SeqLisrtFind(&s, 5);

	if (pos != -1)

		printf("5 is in %d!\n", pos);

	else

		printf("5 is not in %d\n", pos);





	SeqListErase(&s, 1);

	pos = SeqLisrtFind(&s, 5);

	if (pos != -1)

		printf("5 is in %d!\n", pos);

	else

		printf("5 is not in %d\n", pos);



	SeqListPrint(&s);

	SeqLisrtSize(&s);



	SeqListDestroy(&s);



}
