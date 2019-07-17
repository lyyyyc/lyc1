#pragma once

typedef int DLDatatype;

typedef struct DListNode
{
	DLDatatype _data;
	struct DListNode* _pNext;
	struct DListNode* _pPre;
}DLNode,*PDLNode;

void DListInit(PDLNode* pHead);
void DListPushBack(PDLNode pHead,DLDatatype data);
void DListPopBack(PDLNode pHead);
void DListPushFront(PDLNode pHead,DLDatatype data);
void DListPopFront(PDLNode pHead);
void DListInsert(PDLNode pos, DLDatatype data);
void DListErase(PDLNode pos);
void DListClear(PDLNode pHead);
void DListDestroy(PDLNode* pHead);


void TestDList();