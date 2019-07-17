#pragma once
//˳���ṹ
//˳��
//��̬˳���
typedef int DataType;
#define MAX_SIZE 100

#if 0
struct SeqList
{
	DataType _array[MAX_SIZE];  //�����洢˳�����Ԫ��
	int _size;  //˳�������ЧԪ�صĸ���
};

#endif

//��̬˳���
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity;//˳�����ܴ�С
	int _size;//˳�������ЧԪ�صĸ���
}SeqList, * PSeq;

//typedef struct SeqList SeqList;
//typedef struct SeqList* PSeqList;

void SeqListInit(PSeq ps, int capacity);//��ʼ��
void SeqListPushBack(PSeq ps, DataType data);//β��
void SeqListPopBack(PSeq ps);//βɾ
void SeqListPushFront(PSeq ps, DataType data);//ͷ��
void SeqListPopFront(PSeq ps);//ͷɾ
void SeqListInsert(PSeq ps, int pos,DataType data);//����λ�ò�
void SeqListErase(PSeq ps,int pos);//����λ��ɾ
int SeqListFind(PSeq ps, DataType);//����
int SeqListEmpty(PSeq ps);//�Ƿ�Ϊ��
int SeqListSize(PSeq ps);//Ԫ�ظ���
int SeqListCapacity(PSeq ps);//������С
void SeqListClear(PSeq ps);//���
void SeqListRemove(PSeq ps, DataType data);//�Ƴ���һ��ֵΪdata��Ԫ��
void SeqListDestroy(PSeq ps);//����
void CheckCapacity(PSeq ps);//�������
////////////////////////////////
void SeqListBubbleSort(PSeq ps);//ð������
void SeqListRemoveAll(PSeq ps, DataType data);//�Ƴ�����ֵΪdata��Ԫ��



void TestSeqList();//����