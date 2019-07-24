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
	int* p1 = new int;//��̬����һ��int���͵Ŀռ�
	int* p2 = new int(10);//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* p3 = new int[3];//��̬����10��int���͵Ŀռ�
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
	//���뵥��A���͵Ķ���
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);
	//����10��A���͵Ķ���
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
	//���뵥��A���͵Ķ���
	A* p3 = new A;
	delete p3;
	//����10��A���͵Ķ���
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
	Add(1, 2);//���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add(1,2.0);//ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
	//���s���ַ�����size��0�����ı�ײ�ռ��С
	s.clear();
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	s.resize(10, 'a');
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//��s����Ч�ַ��������ӵ�15���������λ����'\0'�������
	s.resize(15);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//��s����Ч�ַ�����������5��
	s.resize(5);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//��s�������ݣ��Ҳ��ı���Ч�ַ�����
	s.reserve(100);
	cout << "s:" << s << endl;
	cout << "size" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << endl;
	//��������С�ڿռ��Сʱ�����Ὣ�ռ���С
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
		//3�ֱ�����ʽ
		//1.for+operator[]
		for (size_t i = 0; i < s.size(); ++i)
			cout << s[i] ;
		cout << endl;
		//2.������
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
	s.push_back(' ');//��s�����ո�
	s.append("hello");//��s��׷���ַ���"hello"
	s += 'b';//��s��׷��һ���ַ�'b'
	s += "it";//��s��׷���ַ���"it"
	cout << s << endl;
	cout << s.c_str << endl;//��C���Է�ʽ��ӡ�ַ���
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