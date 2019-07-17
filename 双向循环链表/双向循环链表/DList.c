#include"DList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

void DListInit(PDLNode* pHead)//������Ϊ����ָ��,pHead������Ϊ��
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
	pNewNode->_pNext = pHead;//�½ڵ���һ��ָ��ͷ�ڵ�
	pNewNode->_pPre = pHead->_pPre;//�½ڵ���һ��ָ��ͷ���ԭ������һ��
	pHead->_pPre->_pNext = pNewNode;//ͷ�ڵ�ԭ������һ������һ��ָ���½ڵ�
	pHead->_pPre = pNewNode;//ͷ�ڵ���һ��ָ���½ڵ�
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
		pHead->_pNext = pCur->_pNext;//pCur��ɾ����pHead��һ��ΪpCur��һ��
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