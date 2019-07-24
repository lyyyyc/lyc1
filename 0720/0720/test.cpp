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

#if 0
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
#endif

#if 0
template<class T>
void Swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}
template<class T>
T Add( T left,  T right)
{
	return left + right;
}
int main()
{
	Add(1, 2);//与非模板函数匹配，编译器不需要特化
	Add(1,2.0);//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
	return 0;
}
#endif

#include<string>

#if 0
int main()
{
	string s;
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		swap(s[begin], s[end]);
		begin++;
		end--;
	}
	return 0;
}
#endif

#if 0
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	size_t begin1 = 0;
	size_t begin2 = 0;
	int count = 0;
	while (s1[begin1] < s1.size())
	{
		if (s1[begin1] == s2[begin2])
		{
			count++;
			begin1++;
			begin2++;
		}
		else
		{
			begin1++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello world");  
	cout << "s:"<<s << endl;
	cout << "size:"<<s.size() << endl;
	cout << "length:"<<s.length() << endl;
	cout << "capacity"<<s.capacity() << endl;
	cout << endl;
	//清空s中字符串，size清0，不改变底层空间大小
	s.clear();
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//将s中有效字符个数增加到10个，多出位置用'a'进行填充
	s.resize(10, 'a');
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//将s中有效字符个数增加到15个，多出的位置用'\0'进行填充
	s.resize(15);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//将s中有效字符个数减少至5个
	s.resize(5);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//将s进行扩容，且不改变有效字符个数
	s.reserve(100);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//函数参数小于空间大小时，不会将空间缩小
	s.reserve(50);
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	return 0;
}
#endif

#if 0
	int main()
	{
		string s("hello world");
		//3种遍历方式
		//1.for+operator[]
		for (size_t i = 0; i < s.size(); ++i)
			cout << s[i] ;
		cout << endl;
		//2.迭代器
		auto it = s.begin();
		while (it != s.end())
		{
			cout << *it ;
			++it;
		}
		cout << endl;
		auto rit = s.rbegin();
		while (rit != s.rend())
		{
			cout << *rit ;
			++rit;
		}
		cout << endl;
		return 0;
	}
#endif

#if 0
int main()
{
	string s;
	s.push_back(' ');//在s后插入空格
	s.append("hello");//在s后追加字符串"hello"
	s += 'b';//在s后追加一个字符'b'
	s += "it";//在s后追加字符串"it"
	cout << s << endl;
	cout << s.c_str << endl;//以C语言方式打印字符串
	cout << endl;
	size_t pos = s.find('b');
	s.insert(pos, 'a');

	return 0;
}
#endif

#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "all" << endl;
	}
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "half" << endl;
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}
#endif

#if 0
class A{};
class B:public A{};

class Person
{
public:
	virtual A* f()
	{
		return new A;
	}
};
class Student:public A
{
public:
	virtual B* f()
	{
		return new B;
	}
};
#endif

#if 0
class Person
{
public:
	 virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	 ~Student()
	{
		cout << "~Student()" << endl;
	}
};
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
}
#endif

#if 0
class Car
{
public:
	virtual void Drive()final{}
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "comfortable" << endl;
	}
};
void Func(Car& c)
{
	c.Drive();
}
int main()
{
	Car c;
	Benz b;
	Func(c);
	Func(b);
	return 0;
}
#endif

#if 0
class Car
{
public:
	virtual void Drive()override{}
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "comfortable" << endl;
	}
};
void Func(Car& c)
{
	c.Drive();
}
int main()
{
	Car c;
	Benz b;
	Func(c);
	Func(b);
	return 0;
}
#endif

#if 0
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "comfortable" << endl;
	}
};
class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "play" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}
int main()
{
	Test();
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void Func()
	{
		cout << "Func()" << endl;
	}
private:
	int _b = 1;
};
int main()
{
	Base b;
	cout << sizeof(b) << endl;
	return 0;
}
#endif

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}