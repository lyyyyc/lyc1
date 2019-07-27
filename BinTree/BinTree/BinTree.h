#pragma once


typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

BTNode* BinTreeCreate(char* array, int size,BTDataType invalid);
BTNode* BinTreeCopy(BTNode* pRoot);

void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

int GetBinTreeSize(BTNode* pRoot);
int GetKLevelNodeCount(BTNode* pRoot,int K);
int GetLeafCount(BTNode* pRoot);
int GetBinTreeHeight(BTNode* pRoot);
BTNode* BinTreeFind(BTNode* pRoot, BTDataType data);

void BinTreeDestory(BTNode** pRoot);

void Test();
