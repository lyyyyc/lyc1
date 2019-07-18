#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

#if 0
void Findnum(string str)
{
	size_t i = 0;
	int count = 0;//计数
	int maxnum = 0;//标记最大数字串长度
	int pos = 0; //最大数字串的开始位置
		while (i < str.size())
		{
			while (!isdigit(str[i]))
				i++;//不是数字就往后走
			while (isdigit(str[i]))
			{
				count++;
				i++;
			}
			if (count > maxnum)
			{
				maxnum = count;//更新maxnum
				pos = i - maxnum;//标记pos
			}
			count = 0;
		}
	for (int j = pos; j < pos + maxnum; j++)
		cout << str[j];
	cout << endl;
}
int main()
{
	string str;
	cin >> str;
	Findnum(str);
	return 0;
}
#endif

#if 0
#include<stdio.h>
int cnt = 0;
int fib(int n)
{
	cnt++;
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 2;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
void main()
{
	fib(8);
	printf("%d", cnt);
}
#endif

#if 0
class A {
public:
	A(char* s)
	{
		cout << s << endl;
	}
	~A(){}
};
class B :virtual public A
{
public:
	B(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1)
	{
		cout << s2 << endl;
	}
};
class D :public B, public C
{
public:
	D(char* s1, char* s2, char* s3, char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main()
{
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
#endif

#if 0
int main()
{
	int x = 1;
	do {
		printf("%2d\n", x++);
	} while (x--);
	return 0;
}
#endif

#if 0
int main()
{
	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s\n", str);
	return 0;
}
#endif

#if 0
int main()
{
	int n[][3] = { 10,20,30,40,50,60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "-" << *(p[0] + 1) << "-" << (*p)[2] << endl;
}
#endif

#if 0
int main()
{
	int a;
	float b, c;
	scanf("%2d%3d%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%f\n", a, b, c);
	return 0;
}
#endif

#if 0
//判断一个字符串是不是回文串
bool is_reback(string& str)
{
	int begin = 0;
	int end = str.size() - 1;

	while (begin < end)
	{
		if (str[begin] != str[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
	//当然可以直接使用STL函数
	/*string s = str;
	reverse(s.begin(), s.end());
	if (s == str)
		return true;
	else
		return false;*/
}
#endif

#if 0
int reback_str_count()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int count = 0;

	for (int i = 0; i <= s1.size(); i++)
	{
		string str1 = s1;//每次重置str1
		str1.insert(i, s2);
		if (is_reback(str1))
		{
			count++;
		}
	}
	return count;
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
int max_cake()
{
	int w;//长(列)
	int h;//宽(行)
	cin >> w >> h;
	int count = 0;

	vector<vector<int>> vv;
	vv.resize(h);//vv有h行

	for (auto& e : vv)
	{
		e.resize(w, 1);//每个小vector有w列，即h*w的二维数组(初始化为1)
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (vv[i][j] == 1)
			{
				count++;

				//与这一行距离是2的行不能有(列不变)
				if (i + 2 < h)
				{
					vv[i + 2][j] = 0;
				}

				//与这一列距离是2的列不能有(行不变)
				if (j + 2 < w)
				{
					vv[i][j + 2] = 0;
				}
			}
		}
	}
	return count;
}
int main()
{
	cout << max_cake() << endl;
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
			cout << a << b << c<<endl;
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
#define SQR(A) A*A
int main()
{
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);
	cout << x << endl;
	return 0;
}
#endif

#if 0
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
int main()
{
	fool();
	return 0;
}
#endif

#if 0
int main(void)
{
	printf("%s , %5.3s\n", "computer", "computer");
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10; 
	double b = 3.14;
	int x = 'A' + a + b;
	return 0;
}
#endif

#if 0
#include<stdio.h>
int main()
{
	/*int i, a[10];
	for (i = 9; i >= 0; i--)
	{
		a[i] = 10 - i;
	}
	printf("%d%d%d", a[2], a[5], a[8]);*/
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	printf("%d %d %d %d", i, a, b, c);
	return 0;
}
#endif

#if 0
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
	B(int i) :data(i)
	{
		cout << "constructed by parameter" <<data<< " ";
	}
private:
	int data;
};
B play(B b)
{
	return b;
}
int main()
{
	B temp = play(5);
	return 0;
}
#endif

#if 0
class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B :public A
{
public:
	virtual	void print()
	{
		cout << "B::print()" << "\n";
	}
};
class C :public A
{
public:
	virtual void print()
	{
		cout << "C::print()" << "\n";
	}
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, * aa, * ab, * ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
	return 0;
}
#endif

#if 0
#include<string>
void test()
{
	string s;
	cin >> s;
	int pos = s.begin;
	for (auto e : s)
	{
		if()
	}
}
#endif

#if 0
int main()
{

	char a[] = "asdd\0kkkk";
		cout << strlen(a) << endl;
		cout << sizeof(a) << endl;

		return 0;
}
#endif

#if 0
#include<cstring>
int main()
{
	char a1[] = "is abc";
	char a2[] = "no abc";
	strcpy(a1, "no");
	if (strcmp(a1, a2) == 0)
		cout << a2;
	else
		cout << a1;
	return 0;
}
#endif

#if 0
int func(unsigned int i)
{
	i = (i & 0x55555555) + (i >> 1) & 0x55555555;
	i = (i & 0x33333333) + (i >> 2) & 0x33333333;
	i = (i & 0x0f0f0f0f) + (i >> 4) & 0x0f0f0f0f;
	i = (i & 0x00ff00ff) + (i >> 8) & 0x00ff00ff;
	i = (i & 0x0000ffff) + (i >> 16) & 0x0000ffff;
	return i;
}
int main()
{
	int i=197;
	cout << func(i) << endl;
	return 0;
}
#endif


#if 0
int getday(int year,int month,int day)
{
	int array[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	int t = array[month - 1];
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		if (month > 2)
		{
			t += 1;
		}
	}
	return t + day;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int i = getday(year, month, day);
		cout << i<<endl;
	}
	return 0;
}
#endif

#if 0
int lucky(int ball, int number[10])
{
	int i=0;
	while (i < 10)
	{
		number[i + 1] += number[i];
		i++;
	}
	int j = 0;
	while (j < 10)
	{
		number[j + 1] *= number[j];
		j++;
	}
	if (number[i + 1] > number[j + 1])
	{
		int k;
	}
}
#endif

#if 0
int main()
{
	const char* szX = "abc";
	const char* szY = "abc";
	return 0;
}	
#endif

#if 0
#include<iostream> 
using namespace std;
class Sample {
public:  Sample(int x) {
	p = &x;
}
		 ~Sample() {
			 if (p) delete p;
		 }
		 int show() {
			 return *p;
		 }
private:
	int* p;
};
int main() {
	Sample S(5);
	cout << S.show() << endl;
	return 0;
}
#endif

#if 0
static int a = 1;
void fun1(void)
{
	a = 2;
}
void fun2(void)
{
	int a = 3;
}
void fun3(void)
{
	static int a = 4;
}
int main()
{
	cout << a << endl;
	fun1();
	cout << a << endl;
	fun2();
	cout << a << endl;
	fun3();
	cout << a << endl;

	return 0;
}
#endif

#if 0
class A
{
public:
	void f()
	{
		printf("A\n");
	}
};
class B:public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};
int main()
{
	A* a = new B;
	a->f();
	delete a;
	return 0;
}
#endif

#if 0
class A
{
public:
	A()
	{
		printf("A");
	}
	~A()
	{
		printf("dea");
	}
};
class B
{
public:
	B()
	{
		printf("B");
	}
	~B()
	{
		printf("deb");
	}
};
class C:public A,public B
{
public:
	C()
	{
		printf("C");
	}
	~C()
	{
		printf("dec");
	}
};
int main()
{
	A *a = new C();
	delete a;
	return 0;
}
#endif

#if 0
#include<fstream>
//使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32];//ip
	int _port;//端口
};
struct ConfigManagre
{
public:
	ConfigManagre(const char* configfile="bitserver .config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		//二进制方式打开写
		ofstream ofs(_configfile, ifstream::out || ifstream::binary);
		ofs.write((const char*)& info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		//二进制方式打开读
		ifstream ifs(_configfile, ifstream::in || ifstream::binary);
		ifs.read((char*)& info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		//C语言先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		//C语言先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile;//配置文件
};
int main()
{
	ConfigManagre cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;

	//二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	//文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	return 0;
}
#endif

#if 0
class Time
{
public:
	Time()
	{
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//无参构造函数
	Date()
	{}
	//含参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	//基本类型（内置类型）
	int _year;
	int _month;
	int _day;
	//自定义类型
	Time _t;
};
int main()
{
	Date d1;//调用无参构造函数
	Date d2(2019, 1, 1);//调用含参构造函数
	Date d3();//声明了d3函数，该函数无参，返回一个日期类型的对象
}
#endif

#if 0
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};
#endif

#if 0
class Date
{
public:
	Date(int year=2019, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}
#endif

#if 0
//全局的operator==
class Date
{
public:
	Date(int year = 2019, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
public:
	int _year;
	int _month;
	int _day;
};
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
	&& d1._month == d2._month
	&& d1._day == d2._day;
}
int main()
{
	Date d1(2019, 1, 1);
	Date d2(2019, 1, 2);
	cout << (d1 == d2) << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 2019, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	/*Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}*/
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(2019, 10, 10);
	d1 = d2;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif

#if 0
void swap_int(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	int a, b;
	swap_int(*a,*b);
	return 0;

}
#endif

#if 0
void print(char* s)
{
	if (*s)
	{
		print(++s);	
		printf("%c", *s);
	}
}
int main()
{
	char str[] = "geneius";
	print(str);
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;
	int* p = (int*)(&a);
	*p = 20;
	cout << a << " " << *p << endl;
	return 0;
}
#endif


#if 0
int main()
{
	int n;
	cin >> n;
	int i = 2;
	int sum = 0;
	int count = 0;
	while (i<=n)
	{
		for (i; i < n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (i % j == 0)
				{
					sum += j;
				}
			}
			if (sum == i)
			{
				count++;
			}
			sum = 0;
			i += 1;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

