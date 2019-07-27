#include"BinTree.h"
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>

BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _BinTreeCreate(BTDataType* array, int size,int *index,BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size&&array[*index]!=invalid)
	{
		pRoot = BuyBinTreeNode(array[*index]);
		++(*index);
		pRoot->_pLeft = _BinTreeCreate(array, size, index, invalid);
		++(*index);
		pRoot->_pRight = _BinTreeCreate(array, size, index,invalid);
	}
		return pRoot;
}
BTNode* BinTreeCopy(BTNode* pRoot)
{
	
}
BTNode* BinTreeCreate(BTDataType* array, int size,BTDataType invalid)
{
	int index = 0;
	return _BinTreeCreate(array, size, &index,invalid);
}
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft); 
		PostOrder(pRoot->_pRight);
		printf("%c", pRoot->_data); 
	}
}
int GetBinTreeSize(BTNode* pRoot)
{
	
}
int GetKLevelNodeCount(BTNode* pRoot,int K)
{
	if (pRoot == NULL||K<=0)
	{
		return 0;
	}
	if (K == 1)
	{
		return 1;
	}
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}
int GetLeafCount(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}
int GetBinTreeHeight(BTNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
}
BTNode* BinTreeFind(BTNode* pRoot, BTDataType data)
{
	BTNode* pNode = NULL;
	if (pRoot == NULL)
	{
		return NULL;
	}
	if (pRoot->_data == data)
	{
		return pRoot;
	}
	if (pNode = BinTreeFind(pRoot->_pLeft, data))
	{
		return pNode;
	}
	return BinTreeFind(pRoot->_pRight, data);
}
void BinTreeDestory(BTNode** pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		BinTreeDestory(&(*pRoot)->_pLeft);
		BinTreeDestory(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void Test()
{
	char* str = "ABD###CE##F";
	BTNode* pRoot=BinTreeCreate(str, strlen(str),'#');
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");
	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");
	printf("后序遍历：");
	PostOrder(pRoot);
	printf("\n");

	GetBinTreeSize(pRoot);
	GetLeafCount(pRoot);


	BinTreeDestory(&pRoot);

}
