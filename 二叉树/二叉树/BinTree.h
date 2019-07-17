#pragma once



typedef int BTDataType;
typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


BTNode* CreateBinTree(BTDataType* array, int size,BTDataType invalid);
BTNode* CopyBinTree(BTNode* pRoot);//¸ù¾Ý¸ÅÄî
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

int GetBinTreeSize(BTNode* pRoot);
int GetKLeaveNodeCount(BTNode* pRoot, int K);
int GetLeafCount(BTNode* pRoot);
int GetBinTreeHeight(BTNode* pRoot);
BTNode* BinTreeFind(BTNode* pRoot, BTDataType data);
void DestoryBinTree(BTNode** pRoot);

void TestBinTree();