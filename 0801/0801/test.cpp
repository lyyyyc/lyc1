#include<iostream>
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