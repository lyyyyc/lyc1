#include"Queue.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}
QueueNode* BuyQueueNode(QDataType data)
{
	QueueNode* QNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NULL == QNewNode)
	{
		assert(0);
		return NULL;
	}
	QNewNode->_data = data;
	QNewNode->_next = NULL;
	return QNewNode;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* qNewNode = BuyQueueNode(data);
	if (QueueEmpty(q))
	{
		q->_front = qNewNode;
		q->_rear = qNewNode;
	}
	else
	{
		q->_rear->_next= qNewNode;
		q->_rear = qNewNode;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* qDelNode = NULL;
	if (QueueEmpty(q))
	{
		return;
	}
	qDelNode = q->_front;
	if (NULL == qDelNode->_next)
	{
		q->_front = NULL;
		q->_rear = NULL;
	}
	else
	{
		q->_front = qDelNode->_next;
	}
	free(qDelNode);
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}
int QueueSize(Queue* q)
{
	assert(q);
	QueueNode* qCur = q->_front;
	int count = 0;
	while (qCur)
	{
		count++;
		qCur = qCur->_next;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;
}
void QueueDestory(Queue* q)
{
	QueueNode* qCur = q->_front;
	while (qCur)
	{
		q->_front = qCur->_next;
		free(qCur);
		qCur = q->_front;
	}
	q->_front = NULL;
	q->_rear = NULL;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("front=%d\n", QueueFront(&q));
	printf("rear=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));
	QueuePop(&q);
	printf("front=%d\n", QueueFront(&q));
	printf("rear=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("front=%d\n", QueueFront(&q));
	printf("rear=%d\n", QueueBack(&q));
	printf("size=%d\n", QueueSize(&q));
	QueuePop(&q);
	printf("size=%d\n", QueueSize(&q));
	QueueDestory(&q);
}