#pragma once
typedef int QDataType;
typedef struct QueueNode {
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue {
	QueueNode* _front;
	QueueNode* _rear;
}Queue;
void QueueInit(Queue* q);
QueueNode* BuyQueueNode(QDataType data);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestory(Queue* q);
void TestQueue();