
#pragma once    //Ԥ�������ֻ����һ��



//��̬˳���



typedef int DataType;

//typedef struct SeqList//���ӵĻ���SeqList,*PSeq��һ�����ͱ���

//�ṹ���һ���ֺţ�����һ���ṹ�����

typedef struct SeqList {//�ṹ��

	DataType* _array;//ָ�룬����ռ䲻�������Լ�������

	int _capacity;//˳�����ܴ�С�����������洢Ԫ��

	int _size;//˳�������ЧԪ�صĸ���

}SeqList, * PSeq;//���ṹ��ָ��ȡ������ΪPSeq;



//˳����ʼ��

void SeqListInit(PSeq Ps, int capacity);

//˳��������

void SeqListDestroy(PSeq ps);

//˳������

void TestSeqList();

//˳����ӡ

void SeqListPrint(PSeq ps);



//��̬˳����β��,��Ԫ�ش����һ����ЧԪ�ط���

void SqListDPushBack(PSeq ps, DataType data);



//��̬˳���βɾ

void SeqListDPopBack(PSeq ps);



//��̬˳����ͷ��

void SeqListDPushFront(PSeq ps, DataType data);



//��̬˳����ͷɾ

void SeqListDPopFront(PSeq ps);

//����λ�ò���

void SeqListInsert(PSeq ps, int pos, DataType data);

//����λ��ɾ��

void SeqListErase(PSeq ps, int pos);









//�鿴ps���˳����Ƿ�Ϊ��

int SeqLisrtEmpty(PSeq ps);



//˳������ݲ���

int  SeqLisrtFind(PSeq ps, DataType data);

//˳���Ԫ�ظ���

int SeqLisrtSize(PSeq ps);

//˳�������

int  SeqLisrtCapacity(PSeq ps);

//˳������

void SeqListClear(PSeq ps);

//��һ������x��Ԫ���Ƴ�

void SeqListRemove(PSeq ps, DataType data);

//�ռ�����

void CheckCapacity(PSeq ps);


