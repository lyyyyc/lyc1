#include<iostream>
#include<stdio.h>
#if 0
//��ͨ�����ռ�
namespace N1
{
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//Ƕ�׵������ռ�
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

//�����ռ�ʹ��
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

//C++�������
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

//ȱʡ����
#if 0
void TestFunc(int a = 0)
{
	cout << a << endl;
}
int main()
{
	TestFunc();//ʹ��Ĭ��ֵ��a=0��
	TestFunc(10);//ʹ��ָ��ֵ��a=10��
	return 0;
}
#endif
//ȫȱʡ����
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

//��ȱʡ����
#if 0
void TestFunc(int a, int b = 10, int c = 20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
int main()
{
	TestFunc(1);//a=1,b��c����
	return 0;
}
#endif

#if 0
//��������
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
//��������
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
//����
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
//������
int main()
{
	const int a = 10;
	//int& ra=a;  ��������ʱ�����aΪ����
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
//ģ��
//����ģ�岻�������ĺ������Ǳ��������ɴ����ģ��
template<typename T>       //ģ������б�
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
	//��Add����ģ�����ʵ����
//	cout << Add(1, 2.0) << endl;
	cout << Add(1, 2) << endl;//��ʽʵ����
	cout << Add(1.0, 2.0) << endl;
	Add(1, (int)2.0);
	Add<double>(1, 2.0);//��ʽʵ����--->ֱ�ӽ�T������ʵ����Ϊ��������
	//������Ҫ��ʵ�ε����ͽ�������,�ڴ���ִ��ʱ�����ܻ��ʵ������ʽ����ת��

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
	Add(1, 2);//��int
	Add<int>(1, 2);//��T����ʽʵ����
	Add<>(1, 2);//��T����ʽʵ����
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
	Add(1, 2);//��int
	Add(1, 2.0);//��T
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
//ģ��ı����Ϊ�����׶�
//1.ʵ����ǰ��ֻ��ģ����м򵥵��﷨���
//2.ʵ�����󣺱������ͻ����T��ʵ�����������ɴ���
template<typename T>
class SeqList
{
public:
	SeqList(size_t capacity=3)
		:_array(new T[capacity])
		,_size(0)
		,_capacity(capacity)
	{}

	//��������&��ֵ���������

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

	//�������
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


