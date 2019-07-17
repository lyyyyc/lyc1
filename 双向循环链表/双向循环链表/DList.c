#include"DList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

void DListInit(PDLNode* pHead)//括号内为二级指针,pHead不可能为空
{
	assert(pHead);
	*pHead = (PDLNode)malloc(sizeof(DLNode));
	if (*pHead == NULL)
	{
		assert(0);
		return;
	}
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

PDLNode BuyDListNode(DLDatatype data)
{
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return;
	}
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
}

void DListPushBack(PDLNode pHead, DLDatatype data)
{
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pHead;//新节点下一个指向头节点
	pNewNode->_pPre = pHead->_pPre;//新节点上一个指向头结点原来的上一个
	pHead->_pPre->_pNext = pNewNode;//头节点原来的上一个，下一个指向新节点
	pHead->_pPre = pNewNode;//头节点上一个指向新节点
}

void DListPopBack(PDLNode pHead)
{
	assert(pHead);
	if (pHead == pHead->_pNext)
	{
		return;
	}
	PDLNode pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}

void DListPushFront(PDLNode pHead, DLDatatype data)
{
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pHead->_pNext;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
	pNewNode->_pPre = pHead;
}

void DListPopFront(PDLNode pHead)
{
	assert(pHead);
	if (pHead->_pNext == pHead)
	{
		return;
	}
	PDLNode pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = pHead;
	free(pDelNode);
}

void DListInsert(PDLNode pos, DLDatatype data)
{
	if (pos == NULL)
	{
		return;
	}
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pNewNode->_pPre->_pNext = pNewNode;
	pos->_pPre = pNewNode;
}

void DListErase(PDLNode pos)
{
	if (pos == NULL)
	{
		return;
	}
	pos->_pNext->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pos->_pNext;
	free(pos);
}

void DListClear(PDLNode pHead)
{
	PDLNode pCur = pHead->_pNext;
	while (pCur!=pHead)
	{
		pHead->_pNext = pCur->_pNext;//pCur已删掉，pHead下一个为pCur下一个
		free(pCur);
		pCur = pHead->_pNext;
	}
	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
}

void DListDestroy(PDLNode* pHead)
{
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}




void TestDList()
{
	PDLNode pHead = NULL;
	DListInit(&pHead);
}