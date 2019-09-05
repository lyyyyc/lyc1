#pragma once

#if 0
template<class K,class V>

struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//balance factor

	AVLTreeNode(const pair<K,V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//插入节点
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//调平衡
		//1.更新平衡因子
		while (parent)
		{
			if (cur = parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)//高度不变，更新完成
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//abs：取绝对值//高度变了，继续更新
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//不平衡，旋转
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		if (parent==_root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (parent==_root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)//左右双旋
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)//右左双旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			parent->_bf = subRL->_bf = subR->_bf = 0;
		}
		else if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (!root)
		{
			return 0;
		}
		int leftheight = _height(root->_left);
		int rightheight = _height(root->_right);

		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool _IsBalance(Node* root)
	{
		if (!root)
		{
			return true;
		}
		int leftheight = _Height(root->_left);
		int rightheight = _Height(root->_right);
		if (rightheight - leftheight != root->_bf)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return abs(leftheight - rightheight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->right);
	}
private:
	Node* _root=nullptr;
};

void TestAVLTree()
{
	AVLTree<int, int> t;
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}
#endif