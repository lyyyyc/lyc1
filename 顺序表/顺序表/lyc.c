
#include"SeqList.h"

#include<malloc.h>

#include<assert.h>

#include<stdio.h>







void SeqListInit(PSeq ps, int capacity) {

	//顺序表初始化,两个参数，初始化哪一个顺序表，顺序表带多少个元素，即容量

	//首先申请空间,sizeof需要字节数，最多存放capacity元素，

	ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);

	//malloc返回值为void*；进行返回值进行强转，在前面加上DataType*

	//开辟成功，返回空间首地址，开辟失败，返回空

	//malloc使用进行判空

	if (NULL == ps->_array) {

		assert(0);//如果申请失败，代码停下，只在调试版本起作用，release版本下会被优化



		return;

	}

	ps->_capacity = capacity;

	ps->_size = 0;

	return;

}



//顺序表的销毁

void SeqListDestroy(PSeq ps) {

	if (ps->_array) {

		free(ps->_array);//释放顺序表空间

		ps->_array = NULL;//空间释放，指针为空

		ps->_capacity = 0;//容量为0

		ps->_size = 0;//包含元素个数为0

	}

}



//尾插

void SqListDPushBack(PSeq ps, DataType data) {

	assert(ps);



	ps->_array[ps->_size] = data;//插入元素.size也是进入尾插最后一个元素下一个位置

	ps->_size++;



}

//尾删

void SeqListDPopBack(PSeq ps) {

	assert(ps);//

	if (SeqLisrtEmpty(ps))

		return;

	ps->_size--;





}

//动态顺序表的头插

void SeqListDPushFront(PSeq ps, DataType data) {

	assert(ps);

	//CheakCapacity(ps);判断顺序表里存在元素

	//将顺序表中所有元素同意向后搬移一个位置

	for (int i = ps->_size - 1; i >= 0; i--) {//i表示搬移的元素

		//for(int i=ps->_size;i>0;i--),如果是size,表示元素被搬移到的位置

		ps->_array[i + 1] = ps->_array[i];

	}

	//插入元素

	ps->_array[0] = data;

	++ps->_size;





}





//动态顺序表的头删

void SeqListDPopFront(PSeq ps) {



	if (SeqLisrtEmpty(ps))

		return;

	for (int i = 1; i < ps->_size; ++i)

		ps->_array[i - 1] = ps->_array[i];



	ps->_size--;



}

//判空



int SeqLisrtEmpty(PSeq ps) {

	assert(ps);

	return 0 == ps->_size;//顺序表中无有效元素



}

//任意位置插入

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









//任意位置删除

void  SeqListErase(PSeq ps, int pos) {

	assert(ps);

	if (pos < 0 || pos >= ps->_size)

		//return;

	//将当前位置之后元素向后搬移一个元素

		for (int i = pos + 1; i < ps->_size; ++i);



}

//顺序表数据查找

int SeqLisrtFind(PSeq ps, DataType data) {



	assert(ps);

	for (int i = 0; i < ps->_size; i++) {

		if (ps->_array[i] == data)

			return i;

	}

	return -1;

}



//顺序表元素个数

int SeqLisrtSize(PSeq ps) {

	assert(ps);

	return 0 == ps->_size;



}

//顺序表容量

int SeqLisrtCapacity(PSeq ps) {

	assert(ps);

	return ps->_capacity;

}



//顺序表清空

void SeqLisrtClear(PSeq ps) {

	assert(ps);

	ps->_size = 0;



}



//移除第一个遇到的数据x

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

	//申请新空间

	int* pTemp = (DataType*)malloc(newCapacity * sizeof(DataType));

	if (NULL == pTemp) {

		assert(0);

		return;

	}

	//malloc(p,size)

	//拷贝元素,

	for (int i = 0; i < ps->_size; ++i)

		pTemp[i] = ps->_array[i];

	//释放旧空间

	free(ps->_array);

	ps->_array = pTemp;

	ps->_capacity = newCapacity;



}





//打印

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
