#include"BinTree.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _CreateBinTree(BTDataType* array, int size,int* index,BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size&& invalid != array[*index])//��ȡ����Ȩ�޳�ͻ
	{
		//���ڵ�
		pRoot = BuyBinTreeNode(array[*index]);
		//����������
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index,invalid);
		//����������
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index,invalid);
	}
	return pRoot;
}
BTNode* CreateBinTree(BTDataType* array, int size,BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index,invalid);
}

void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot)
{
	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c ", pRoot->_data);
}

int GetLeafCount(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
	{
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}


void DestoryBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestoryBinTree(&(*pRoot)->_pLeft);
		DestoryBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}


void TestBinTree()
{
	char* str ="ABD###CE##F";
	BTNode* pRoot = CreateBinTree(str, strlen(str),'#');
	printf("ǰ����������");
	PreOrder(pRoot);
	printf("\n");
	printf("������������");
	InOrder(pRoot);
	printf("\n");
	printf("������������");
	PostOrder(pRoot);
	printf("\n");

	DestoryBinTree(&pRoot);
}