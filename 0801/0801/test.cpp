#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory>
using namespace std;

#if 0
void func(const int& v1, const int& v2)
{
	std::cout << v1 << ' ';
	std::cout << v2 << ' ';
}
int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	return 0;
}
#endif

#if 0
#include "stdio.h" 
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived : public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base* pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));
	printf("%d,", pObj->Bar(100));
}
#endif

#include<vector>

#if 0
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
}
int main()
{
	int a[5] = { 4,5,2,3,1 };
	MergeSort(a, 5);
	return 0;
}
#endif

#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr=nullptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	SmartPtr<int> sp(tmp);
}
int main()
{
	//try {
		int a[5] = { 4,5,2,3,1 };
		MergeSort(a, 5);
	//}
	//catch (const exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	return 0;
}
#endif
#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
private:
	T* _ptr;
};
struct Date
{
	int _year;
	int _month;
	int _day;
};
int main()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;

	SmartPtr<int> sparray(new Date);
	sparray->_year = 2018;
	sparray->_month = 1;
	sparray->_day = 1;
	
}
#endif

#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}
private:
	T* _ptr;
};
int main()
{
	int* p = new int;
	SmartPtr<int> sp(p);
	//delete p;
	return 0;
}
#endif

#if 0
#include<iostream>

using namespace std;

int maxTimes(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n <= 3)
	{
		return 1;
	}
	return 1 + maxTimes((n + 2) / 3);
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		cout << maxTimes(n) << endl;
	}
	return 0;
}
#endif

#if 0
//#include<iostream> 
//using namespace std;
class B
{
public:
	B()
	{
		cout << "default constructor" << " ";
	}
	~B()
	{
		cout << "destructed" << " ";
	}
	B(int i) :
		data(i)
	{
		cout << "constructed by parameter" << data << " ";
	}
private:
	int data;
};
B Play(B b)
{
	return b;
}
int main(int argc, char* argv[])
{
	B temp = Play(5);
	return 0;
}
#endif

#if 0
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

struct A
{
	int a;
	int b;
	int c;
};

void TestAuto1()
{
	bit::auto_ptr<int> ap1(new int);
	*ap1 = 10;

	int a = 10;
	int* pa = &a;
	A aa;
	A* paa = &aa;
	paa->a;
	
	bit::auto_ptr<A> ap2(new A);
	(*ap2).a;
	ap2->a;
}

void TestAuto2()
{
	bit::auto_ptr<int>ap1(new int);
	bit::auto_ptr<int>ap2(ap1);

	bit::auto_ptr<int>ap3;
	ap3 = ap2;
}

int main()
{
	TestAuto2();
	return 0;
}
#endif


#if 0
//��Դ����Ȩ������Դ�ͷŵ�Ȩ������ת��
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
				
			}
			return *this;
		}
		~auto_ptr()
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
				_owner = false;
				_ptr = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;
		}
	private:
		T* _ptr;
		mutable bool _owner;//��Դ���ͷ���
	};
}
void TestAutoPtr()
{
	bit::auto_ptr<int>ap1(new int);
	bit::auto_ptr<int>ap2(ap1);
	*ap1 = 10;
	*ap2 = 20;

	bit::auto_ptr<int>ap3;
	ap3 = ap2;
}
int main()
{
	TestAutoPtr();
	return 0;
}
#endif

#if 0
namespace bit
{
	template<class T>
	class unique_ptr//��Դ��ռ��������������
	{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator* ()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//��ֹ������
		//C++98
	/*private:
		unique_ptr(const unique_ptr<T>&);
		unique_ptr<T>& operator=(const unique_ptr<T>& ap);*/
		
		//C++11 delete:��ֹĬ�ϳ�Ա����������
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;
	private:
		T* _ptr;
	};
}
class A
{
public:
	A(int a)
		:_a(a)
	{}
	A() = default;//����Ĭ�ϵĹ��캯��
private:
	int _a;
};
void TestA()
{
	A a1(10);
	A a2;
}
void TestUniquePtr()
{
	bit::unique_ptr<int>up1(new int);
	bit::unique_ptr<int>up2(up1);
	bit::unique_ptr<int>up3;
	up3 = up1;
}
int main()
{
	TestUniquePtr();
	return 0;
}
#endif

#if 0
#include<memory>
int main()
{
	/*auto_ptr<int>ap1(new int);
	auto_ptr<int>ap2(ap1);
	auto_ptr<int>ap3;
	ap3 = ap2;*/
	unique_ptr<int>up1(new int);
	unique_ptr<int>up2(up1);
	unique_ptr<int>up3;
	up3 = up2;
	return 0;
}
#endif

#if 0
namespace bit
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{
			if (_ptr)
			{
				_count = 1;
			}
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			_count++;
		}
		~shared_ptr()
		{
			if (_ptr && 0 == --_count)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	private:
		T* _ptr;//��Դ
		static int _count;
	};
	template<class T>
	int shared_ptr<T>::_count = 0;
}
void TestSharedPtr()
{
	bit::shared_ptr<int>sp1(new int);
	bit::shared_ptr<int>sp2(sp1);
	bit::shared_ptr<int>sp3(new int);
}
int main()
{
	TestSharedPtr();
	return 0;
}
#endif

#if 0
namespace bit
{
	//ֻ�ܹ���new����Դ
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
			{
				++(*_pCount);
			}
		}
		//sp2=sp1
		//sp2��û�й�����Դ����sp1ֱ�ӹ���
		//sp2�����Թ�����Դ��
		//sp2����������������Դ������-1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//�õ�ǰ��Դ�������Դ�Ͽ���ϵ
				release();
				//�õ�ǰ������sp������Դ
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
				{
					++(*_pCount);
				}
			}
			return *this;
		}
		~shared_ptr()
		{
			release();
		}
		int use_count()
		{
			return *_pCount;
		}
	private:
		void release()
		{
			if (_ptr && 0 == -- * _pCount)
			{
				delete _ptr;
				_ptr = nullptr;
				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr;//��Դ
		int* _pCount;//ָ������Ŀռ�
	};
}
void TestSharedPtr1()
{
	bit::shared_ptr<int>sp1(new int);
	bit::shared_ptr<int>sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	bit::shared_ptr<int>sp3(new int);
	cout << sp3.use_count() << endl;
}
void TestSharedPtr2()
{
	bit::shared_ptr<int>sp1(new int);
	bit::shared_ptr<int>sp2;
	sp2 = sp1;

	bit::shared_ptr<int>sp3(new int);
	bit::shared_ptr<int>sp4(new int);
	sp4 = sp3;

	bit::shared_ptr<int>sp5(new int);
	bit::shared_ptr<int>sp6(new int);
	bit::shared_ptr<int>sp7(sp6);
	sp6 = sp5;
}
int main()
{
	TestSharedPtr2();
	return 0;
}
#endif


//����ɾ����
//new
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};
//malloc
template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};
//�ļ�
class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};
namespace bit
{
	//������Դ����ȥ�ͷ�
	//������Դʱ��������ʽ�������
	template<class T,class DF=DFDel<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
			{
				++(*_pCount);
			}
		}	
		//sp2=sp1
		//sp2��û�й�����Դ����sp1ֱ�ӹ���
		//sp2�����Թ�����Դ��
		//sp2����������������Դ������-1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//�õ�ǰ��Դ�������Դ�Ͽ���ϵ
				release();
				//�õ�ǰ������sp������Դ
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
				{
					++(*_pCount);
				}
			}
			return *this;
		}
		~shared_ptr()
		{
			release();
		}
		int use_count()
		{
			return *_pCount;
		}
	private:
		void release()
		{
			if (_ptr && 0 == -- * _pCount)
			{
				//delete _ptr;
				//DF df;
				//df.operator()(_ptr)
				DF()(_ptr);
				_ptr = nullptr;
				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr;//��Դ
		int* _pCount;//ָ������Ŀռ�
	};
}
void TestSharedPtr()
{
	bit::shared_ptr<int>sp1(new int);
	bit::shared_ptr<int>sp2((int*)malloc(sizeof(int)));
	bit::shared_ptr<FILE>sp3(fopen("1.txt", "w"));

}
int main()
{
	TestSharedPtr();
	return 0;
}