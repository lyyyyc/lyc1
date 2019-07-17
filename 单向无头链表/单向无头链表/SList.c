#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}

PNode BuySListNode(SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (NULL == s->_pHead)//空链表
	{
		s->_pHead = pNewNode;
	}
	else//链表非空
	{
		//找链表中最后一个节点
		PNode pCur = s->_pHead;
		while (NULL != pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(SList* s)
{
	assert(s);
	if (s->_pHead == NULL)//空链表
	{
		return;
	}
	else if (s->_pHead->_pNext ==NULL)//链表只有一个节点
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else//链表有多个节点
	{
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		free(pCur);
		pPre->_pNext = NULL;
	}
}

void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

void SListPopFront(SList* s)
{
	assert(s);
	if (s->_pHead == NULL)
	{
		return;
	}
	else
	{
		PNode pDelNode = s->_pHead;
		s->_pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

void SListInsert(PNode pos, SDataType data)
{
	if (pos == NULL)
	{
		return;
	}
	else
	{
		PNode pNewNode = BuySListNode(data);
		pNewNode->_pNext = pos->_pNext;
		pos->_pNext = pNewNode;
	}
}

void SListErase(SList* s, PNode pos)
{
	assert(s);
	if (pos == NULL || s->_pHead == NULL)
	{
		return;
	}
	else if(s->_pHead==pos)
	{
		s->_pHead = pos->_pNext;
	}
	else
	{
		PNode pPrePos = s->_pHead;;
		while (pPrePos && pPrePos->_pNext != pos)
		{
			pPrePos = pPrePos->_pNext;
		}
		if (pPrePos)
		{
			pPrePos->_pNext = pos->_pNext;
		}
	}
	free(pos);
}

PNode SListFind(SList* s, SDataType data)
{
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		else
		{
			pCur = pCur->_pNext;
		}		
	}
	return NULL;
}

int SListSize(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	size_t count = 0;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
		
	}
	printf("size=%d", count);
	printf("\n");
	return count;
}

int SListEmpty(SList* s)
{
	assert(s);
	if (s->_pHead == NULL)
	{
		return;
	}
}

void SListClear(SList* s)
{
	assert(s);
	if (s->_pHead == NULL)
	{
		return;
	}
	s->_pHead->_pNext = NULL;
}

void SListDestroy(SList* s)
{
	s->_pHead = NULL;
}

void PrintSList(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

void TestSList1()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	PrintSList(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	PrintSList(&s);
}

void TestSList2()
{
	SList s;
	SListInit(&s);
	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);
	PrintSList(&s);
	SListSize(&s);
	SListPopFront(&s);
	PrintSList(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	PrintSList(&s);
	SListDestroy(&s);
	PrintSList(&s);
}

void TestSList()
{
	TestSList1();
	TestSList2();
}