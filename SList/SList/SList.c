#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
void SListInit(SList* s)
{
	assert(s);
	s->_head = NULL;
}
pNode BuySListNode(SLTDataType data)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}
	newNode->_data = data;
	newNode->_next = NULL;
	return newNode;
}

void SListPushBack(SList* s, SLTDataType data)
{
	assert(s);
	pNode newNode = BuySListNode(data);
	if (s->_head == NULL)
	{
		s->_head = newNode;
	}
	else
	{
		pNode cur = s->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newNode;
	}
}

void SListPopBack(SList* s)
{
	assert(s);
	if (s->_head == NULL)
	{
		return;
	}
	else if (s->_head->_next == NULL)
	{
		free(s->_head);
		s->_head = NULL;
	}
	else
	{
		pNode pre = NULL;
		pNode cur = s->_head;
		while (cur->_next)
		{
			pre = cur;
			cur = cur->_next;
		}
		free(cur);
		pre->_next = NULL;
	}
}

void SListPushFront(SList* s, SLTDataType data)
{
	assert(s);
	pNode newNode = BuySListNode(data);
	newNode->_next = s->_head;
	s->_head = newNode;
}

void SListPopFront(SList* s)
{
	assert(s);
	if (s->_head == NULL)
	{
		return;
	}
	else
	{
		pNode del = s->_head;
		s->_head = del->_next;
		free(del);
	}
}

pNode SListFind(SList* s, SLTDataType data)
{
	assert(s);
	pNode cur = s->_head;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}

void SListInsertAfter(pNode pos, SLTDataType data)
{
	if (pos == NULL)
	{
		return;
	}
	else
	{
		pNode newNode = BuySListNode(data);
		newNode->_next = pos->_next;
		pos->_next = newNode;
	}
}
void SListEraseAfter(pNode pos)
{
	
}