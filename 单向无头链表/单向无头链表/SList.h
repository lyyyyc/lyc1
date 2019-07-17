#pragma once
typedef int SDataType;
//链表的节点
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node,*PNode;
typedef struct SList
{
	PNode _pHead;//指向链表中的第一个节点
}SList;
void SListInit(SList* s);
void SListPushBack(SList* s, SDataType data);
void SListPopBack(SList* s);
void SListPushFront(SList* s, SDataType data);
void SListPopFront(SList* s);
void SListInsert(PNode pos, SDataType data);
void SListErase(SList* s,PNode pos);
PNode SListFind(SList* s, SDataType data);
int SListSize(SList* s);
int SListEmpty(SList* s);
void SListClear(SList* s);
void SListDestroy(SList* s);
void TestSList();