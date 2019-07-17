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
	if (*index < size&& invalid != array[*index])//读取访问权限冲突
	{
		//根节点
		pRoot = BuyBinTreeNode(array[*index]);
		//根的左子树
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index,invalid);
		//根的右子树
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
	printf("前序遍历结果：");
	PreOrder(pRoot);
	printf("\n");
	printf("中序遍历结果：");
	InOrder(pRoot);
	printf("\n");
	printf("后序遍历结果：");
	PostOrder(pRoot);
	printf("\n");

	DestoryBinTree(&pRoot);
}