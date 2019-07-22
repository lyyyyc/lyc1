#include<iostream>
using namespace std;

#if 0
int f(int n)
{
	static int i= 1;
	if (n >= 5)
	{
		return n;
	}
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	cout << f(1) << endl;
	return 0;
}
#endif

#if 0
int getTotalCount(int n)
{
	
	if (n<=2)
		return 1;
	return getTotalCount(n - 1) + getTotalCount(n - 2);
}
int main()
{
	int n;
	cin >> n;
	int i = getTotalCount(n);
	cout << i<< endl;
	return 0;
}
#endif

#if 0
void Test()
{
	int* p1 = new int;//动态申请一个int类型的空间
	int* p2 = new int(10);//动态申请一个int类型的空间并初始化为10
	int* p3 = new int[3];//动态申请10个int类型的空间
	delete p1;
	delete p2;
	delete[] p3;
}
#endif

#include<malloc.h>

#if 0
class A
{
public:
	A()
		:_data(0)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _data;
};
int main()
{
	//申请单个A类型的对象
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);
	//申请10个A类型的对象
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
	//申请单个A类型的对象
	A* p3 = new A;
	delete p3;
	//申请10个A类型的对象
	A* p4 = new A[10];
	delete[] p4;
	return 0;
}
#endif

#if 0
struct ListNode
{
	ListNode* _next;
	ListNode* _pre;
	int _data;
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout<<"memory pool deallocate"<<endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_pre = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}
#endif

#include<string>
int circu(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	size_t count = 0;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		string s = s1;
		s.insert(i, s2);
		if (circu(s))
			++count;
	}
	cout << count << endl;
	return 0;
}