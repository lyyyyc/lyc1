#pragma once
//顺序表结构
//顺序
//静态顺序表
typedef int DataType;
#define MAX_SIZE 100

#if 0
struct SeqList
{
	DataType _array[MAX_SIZE];  //用来存储顺序表中元素
	int _size;  //顺序表中有效元素的个数
};

#endif

//动态顺序表
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity;//顺序表的总大小
	int _size;//顺序表中有效元素的个数
}SeqList, * PSeq;

//typedef struct SeqList SeqList;
//typedef struct SeqList* PSeqList;

void SeqListInit(PSeq ps, int capacity);//初始化
void SeqListPushBack(PSeq ps, DataType data);//尾插
void SeqListPopBack(PSeq ps);//尾删
void SeqListPushFront(PSeq ps, DataType data);//头插
void SeqListPopFront(PSeq ps);//头删
void SeqListInsert(PSeq ps, int pos,DataType data);//任意位置插
void SeqListErase(PSeq ps,int pos);//任意位置删
int SeqListFind(PSeq ps, DataType);//查找
int SeqListEmpty(PSeq ps);//是否为空
int SeqListSize(PSeq ps);//元素个数
int SeqListCapacity(PSeq ps);//容量大小
void SeqListClear(PSeq ps);//清空
void SeqListRemove(PSeq ps, DataType data);//移除第一个值为data的元素
void SeqListDestroy(PSeq ps);//销毁
void CheckCapacity(PSeq ps);//检测容量
////////////////////////////////
void SeqListBubbleSort(PSeq ps);//冒泡排序
void SeqListRemoveAll(PSeq ps, DataType data);//移除所有值为data的元素



void TestSeqList();//测试