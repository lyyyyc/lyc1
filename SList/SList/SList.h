#pragma once

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}Node,*pNode;

typedef struct SList
{
	pNode _head;
}SList;

void SListInit(SList* s);
void SListDestory(SList* s);

pNode BuySListNode(SLTDataType data); 
void SListPushBack(SList* s, SLTDataType data);
void SListPopBack(SList* s);
void SListPushFront(SList* s, SLTDataType data);
void SListPopFront(SList* s);
pNode SListFind(SList* s, SLTDataType data);
// ��pos�ĺ�����в��� 
void SListInsertAfter(pNode pos, SLTDataType data);
// ��pos��ǰ����в���
void SListEraseAfter(pNode pos);
void SListRemove(SList* s, SLTDataType data);

void SListPrint(SList* s);
void TestSList(); 