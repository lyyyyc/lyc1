#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
class Time
{
public:
	Time(int hour=0,int minute=0,int second=0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
#endif

#if 0
//һ���ഴ������ĸ���������(��Ӧ�������Ķ�������������ж��󶼿��Է��ʣ�������
int g_count=0;
class Test
{
public:
	Test()
		:_t(0)
	{
		++g_count;
	}
	Test(const Test& t)
	{
		g_count++;
	}
	~Test()
	{
		--g_count;
	}
private:
	int _t;
};
void TestFunc()
{
	Test t1, t2;
	cout << g_count << endl;
}
int main()
{
		cout << g_count << endl;
		Test t1, t2, t3;
		cout << g_count << endl;
		Test t4(t1);
		cout << g_count << endl;
		TestFunc();
		cout << g_count << endl;
		return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
		:_t(0)
	{
		++_count;
	}
	Test(const Test& t)
	{
		_count++;
	}
	~Test()
	{
		--_count;
	}
private:
	int _t;
	static int _count;//��̬��Ա����
};
int Test::_count = 0;
int main()
{
	Test t1, t2, t3;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	Date d(2019, 7, 4);
	d.PrintDate();
	cout << d << endl;
	return 0;
}
#endif

#if 0
class Time
{
	friend class Date;
public:
	Time(int hour = 0,int minute=0,int second=0)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
		,_t(11,11,11)
	{}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << " " << _t._hour << ":" << _t._minute << ":" << _t.second << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d(2019, 7, 4);
	d.PrintDate();
	return 0;;
}
#endif

#if 0
#include<queue>
#include<vector>
class Date
{
	class Less//�ڲ���
	{
	public:
		bool operator()(const Date* pLeft, const Date* pRight)
		{
			return pLeft->_day<pRight->_day;
		}
	};
	void TestFunc()
	{
		Date d1(2019, 7, 4);
		Date d2(2019, 7, 5);
		Date d3(2019, 7, 3);
		priority_queue<Date*,vector<Date*>,Less> q;
		q.push(&d1);
		q.push(&d2);
		q.push(&d3);
	}
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	
	return 0;
}
#endif

#if 0
//��1+2+3+....+n
//���ù��캯��
//1.���캯���ڴ�������ʱ���Զ����е���
//2.ͳ�ƶ���ĸ���
class Solution
{
public:
	class Sum
	{
	public:
		Sum()
		{
			++_count;
			_total += _count;
		}
		static void ReSet()
		{
			_count = 0;
			_total = 0;
		}
		static int GetSum()
		{
			return _total;
		}
	private:
		static int _count;
		static int _total;
	};
	int Sum_Solution(int n)
	{
		Sum::ReSet();
		//Sum s[n];
		Sum* ps = new Sum[n];
		delete[] ps;
		return Sum::GetSum();
	}
};
int Solution::Sum::_count = 0;
int Solution::Sum::_total = 0;
#endif

#if 0
int GetMonthOfDay(int year, int month)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear(year) )
	{
		days[2] += 1;
	}
	return days[month];
}
bool IsVliadDate(int year, int month, int day)
{
	if(year>0&&month>=1&&month<=12&&day>0&&day<=GetMonthOfDay(year,month))
		return true;
	return false;
}
int IsLeapYear(int year)
{
	if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
	{
		return true;
	}
	return false;
}
int ConvertDate(int year, int month, int day)
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int totalDays = 0;
	if (IsLeapYear(year) )
	{
		days[2] += 1;
	}
	for (int i = 1; i < month;++i)
	{
		totalDays += days[i];
	}
	totalDays += day;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		if (IsVliadDate(year, month, day))
		{
			cout << ConvertDate(year, month, day) << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test::Test()" << endl;
	}
	~Test()
	{
		cout << "Test::~Test()" << endl;
	}
	int _t;
};
int main()
{
	Test* pt = new Test;
	return 0;
}
#endif
#if 0
void* operator new(size_t size, char* fileName, char* funcName, size_t lineno)
{
	cout << fileName << ":" << funcName << ":" <<lineno<<":"<< size << endl;
	return malloc(size);
}
int main()
{
	int* p = new(__FILE__, __FUNCDNAME__, __LINE__) int;
	delete p;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	{
		if (b != 2 || c-- != 3)
		{
			cout << a << b << c << endl;
		}
		else {
			cout << a << b << c << endl;
		}
	}
	else {
		cout << a << b << c << endl;
	}
	return 0;
}
#endif

#if 0
#include<assert.h>
//������ģ�����
namespace bite
{
	template<class T,size_t N>
	class array
	{
	public:
		array()
			: _size(0)
		{
			//N = 10;NΪ���������ܸ�ֵ
		}
		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}
	private:
		T _array[N];
		size_t _size;
	};
}
int main()
{
	bite::array<int, 10>arr1;
	int a = 10;
	int b = 20;
	//bite::array<int, a+b>arr1;���뱨��a+b�Ľ���ڱ����ڼ��޷�ȷ������ģ���еľ�̬����û�а취����
	return 0;
}
#endif

#if 0
//Max����ģ����ڴ󲿷����Ͷ����Դ������Ǵ�����char* (�ַ����ıȽϹ���)
//Max����ģ������char*�������⴦��--�ػ�
//1.�����к���ģ��  2.�ػ���ʲô����
template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}
//��򵥵ķ�ʽ--���޷��������͵���ͨ����ֱ�Ӹ���
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
	{
		return left;
	}
	return right;
}
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;
	const char* ps1 = "world";
	const char* ps2 = "hello";
	cout << Max(ps1, ps2) << endl;//�������ַ���ַ���Ƚ�
	return 0;
}
#endif

#if 0
//��ģ���ȫ�ػ�
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//Data��ģ���ȫ�ػ�
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
int main()
{
	Data<int, char>d1;
	Data<long, char>d2;
	return 0;
}
#endif

#if 0
//��ģ���ƫ�ػ���1.�����ػ� 2.��ģ�������һ������������
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//Data��ģ�岿���ػ�
//��ʵ����Data��ģ��ʱ��ֻҪ�ڶ�������ʹ��int����󶼻�ʹ�ò����ػ�
template<class T1>
class Data<T1,int>
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};
//��ģ��������и���һ������������
//�����ģ��������������ָ��ķ�ʽ����ʵ����������ִ�������ػ��汾
template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};
int main()
{
	Data<int, int>d1;
	Data<double, int>d2;
	Data<int, double>d3;

	Data<int*, char*>d4;
	return 0;
}
#endif

#if 0
#include<string>
#include<cstring>
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) +1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
//дһ��ͨ�õĿ����������������Ͷ����Խ��п���
template<class T>
void Copy(T* dst, T* src, size_t size)
{
	//�������ͺ��Զ�������
	if ()
	{
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			det[i] = src[i];
		}
	}
	/*//memcpy(dst, src, sizeof(T) * size);
	//ȱ�㣺1.�ڴ�й¶ 2.ǳ����
	//�ŵ㣺Ч�ʸ�
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
	//�ŵ㣺һ���������
	//ȱ�㣺Ч�ʵ�*/
}
int main()
{
	int array1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int array2[sizeof(array1) / sizeof(array1[0])];
	Copy(array2, array1, 10);

	String s1[] = { "1111","2222","3333" };
	String s2[3];
	Copy(s2, s1, 3);
	return 0;
}
#endif

#if 0
#include"TestTemple.h"
int main()
{
	Add(1, 2);
	Sub(2, 1);
	return 0;
}
#endif

#if 0
void Swap(int& left,int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
#endif

#if 0
#include<time.h>
struct A
{
	int a[10000];
};
A a;
A TestFunc1()
{
	return a;
}
A& TestFunc2()
{
	return a;
}
void TestReturnByRefOrValue()
{
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1();
	}
	size_t end1 = clock();
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2();
	}
	size_t end2= clock();
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestReturnByRefOrValue();
	}
	return 0;
}
#endif

#if 0
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x; 
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}
#endif

//��Χforѭ��
int main()
{
	int array[] = { 1,2,3,4,5 };
	for (auto& e : array)
	{
		e *= 2;
	}
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}