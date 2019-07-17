#include<iostream>
#include<stdio.h>
#if 0
//普通命名空间
namespace N1
{
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//嵌套的命名空间
namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//命名空间使用
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
using N::b;
using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	Add(10, 20);
	return 0;
}
#endif

//C++输入输出
using namespace std;
#if 0
int main()
{
	cout << "hello world" << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << " " << c << endl;
	return 0;
}
#endif

//缺省参数
#if 0
void TestFunc(int a = 0)
{
	cout << a << endl;
}
int main()
{
	TestFunc();//使用默认值（a=0）
	TestFunc(10);//使用指定值（a=10）
	return 0;
}
#endif
//全缺省参数
#if 0
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << a<<endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
int main()
{
	TestFunc();
	return 0;
}
#endif

//半缺省参数
#if 0
void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
int main()
{
	TestFunc(1);//a=1,b、c不变
	return 0;
}
#endif

#if 0
//函数重载
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	cout<<Add(10, 20)<<endl;
	cout<<Add(10.1, 20.0)<<endl;
	cout<<Add(10L, 20L)<<endl;
	return 0;
}
#endif

#if 0
//名字修饰
int Add(int left, int right);
int main()
{
	Add(1, 2);
	return 0;
}
#endif

#if 0
//extern "C"
extern "C" int Add(int left, int right);
int main()
{
	cout<<Add(1, 2)<<endl;
	return 0;
}
#endif

#if 0
//引用
int main()
{
	int a = 10;
	int& ra = a;
	cout << &a << endl;
	cout << &ra << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	int& ra = a;
	int& rra = a;
	cout << &a << ' ' << &ra << ' ' << &rra << endl;
	return 0;
}
#endif

#if 0
//常引用
int main()
{
	const int a = 10;
	//int& ra=a;  此语句编译时会出错，a为常量
	const int& ra = a;
	return 0;
}
#endif

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

#if 0
//模板
//函数模板不是真正的函数，是编译器生成代码的模具
template<typename T>       //模板参数列表
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}
//template<typename T1, typename T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << typeid(T1).name()<<' '<<typeid(T2).name() << endl;
//	return left + right;
//}
int main()
{
	//对Add函数模板进行实例化
//	cout << Add(1, 2.0) << endl;
	cout << Add(1, 2) << endl;//隐式实例化
	cout << Add(1.0, 2.0) << endl;
	Add(1, (int)2.0);
	Add<double>(1, 2.0);//显式实例化--->直接将T的类型实例化为参数类型
	//，不需要对实参的类型进行推演,在代码执行时，可能会对实参做隐式类型转化

	return 0;
}
#endif

#if 0
template<typename T>
T Add(T left, T right)
{
	return left + right;
}
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	Add(1, 2);//调int
	Add<int>(1, 2);//调T，显式实例化
	Add<>(1, 2);//调T，隐式实例化
	return 0;
}
#endif

#if 0
template<typename T1,typename T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	Add(1, 2);//调int
	Add(1, 2.0);//调T
	return 0;
}
#endif

#if 0
template<class T>
T Add(const T& left,const T& right)
{
	return left + right;
}
class Complex
{
public:
	Complex(double real, double image)
		:_real(real)
		, _image(image)
	{}
	Complex operator+(const Complex& c)const
	{
		/*Complex temp(*this);
		temp._real += c._real;
		temp._image += c._image;
		return temp;*/

		return Complex(_real + c._real, _image + c._image);
	}
private:
	double _real;
	double _image;
};
int main()
{
	Add(1, 2);
	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);
	Add(c1, c2);
	return 0;
}
#endif

#if 0
//模板的编译分为两个阶段
//1.实例化前：只对模板进行简单的语法检测
//2.实例化后：编译器就会根据T的实际类型来生成代码
template<typename T>
class SeqList
{
public:
	SeqList(size_t capacity=3)
		:_array(new T[capacity])
		,_size(0)
		,_capacity(capacity)
	{}

	//拷贝构造&赋值运算符重载

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}

	void PushBack(const T& data);
	
	void PopBack()
	{
		if (!Empty())
			return;
		--_size;
	}

	//随机访问
	T& operator[](size_t index)
	{
		return _array[index];
	}
	
	T& Front()
	{
		return _array[0];
	}

	size_t Size()const
	{
		return _size;
	}
	
	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()
	{
		return 0 == _size;
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

template<typename T>
void SeqList<T>::PushBack(const T& data)
{
	//CheckCapacity();
	_array[_size++] = data;
}
int main()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << array[5] << endl;

	SeqList <int>s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	cout << s1.Front() << endl;
	s1[1] = 10;
	SeqList<double>s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	cout << s2.Size();
	cout << s2.Capacity() << endl;
	return 0;
}
#endif


