
#pragma once    //预处理命令：只包含一次



//动态顺序表；



typedef int DataType;

//typedef struct SeqList//不加的话。SeqList,*PSeq是一个类型别名

//结构体加一个分号，等于一个结构体变量

typedef struct SeqList {//结构体

	DataType* _array;//指针，如果空间不够，可以继续申请

	int _capacity;//顺序表的总大小，容量，最多存储元素

	int _size;//顺序表中有效元素的个数

}SeqList, * PSeq;//给结构体指针取别名，为PSeq;



//顺序表初始化

void SeqListInit(PSeq Ps, int capacity);

//顺序表的销毁

void SeqListDestroy(PSeq ps);

//顺序表测试

void TestSeqList();

//顺序表打印

void SeqListPrint(PSeq ps);



//动态顺序表的尾插,将元素从最后一个有效元素放入

void SqListDPushBack(PSeq ps, DataType data);



//动态顺序表尾删

void SeqListDPopBack(PSeq ps);



//动态顺序表的头插

void SeqListDPushFront(PSeq ps, DataType data);



//动态顺序表的头删

void SeqListDPopFront(PSeq ps);

//任意位置插入

void SeqListInsert(PSeq ps, int pos, DataType data);

//任意位置删除

void SeqListErase(PSeq ps, int pos);









//查看ps这个顺序表是否为空

int SeqLisrtEmpty(PSeq ps);



//顺序表数据查找

int  SeqLisrtFind(PSeq ps, DataType data);

//顺序表元素个数

int SeqLisrtSize(PSeq ps);

//顺序表容量

int  SeqLisrtCapacity(PSeq ps);

//顺序表清空

void SeqListClear(PSeq ps);

//第一个遇到x的元素移除

void SeqListRemove(PSeq ps, DataType data);

//空间扩容

void CheckCapacity(PSeq ps);


