#include<iostream>

using namespace std;

#if 0
int main()
{
	/*int i = 1;
	//隐式类型转换
	double d = i;
	printf("%d,%.2f\n", i, d);

	int* p = &i;
	//显示的强制类型转换
	int address = (int)p;
	printf("%x,%d\n", p, address);*/

	/*int i = 10;
	size_t pos = 0;
	while (i >= pos)
	{
		cout << i << endl;
		--i;
	}*/

	/*double d = 1.111;
	int i1 = d;

	int i2 = static_cast<int>(d);//对应隐式类型转换：相近类型

	int* p = reinterpret_cast<int*>(i2);//对应隐式类型转化：无关类型

	//const int x = 10;
	volatile const int x = 10;//volatile:去内存取变量
	///const int* cpx = &x;
	volatile const int* cpx = &x;

	int* px = const_cast<int*>(cpx);
	*px = 20;

	cout << x << endl;
	cout << *px << endl;*/

	typedef void(*FUNC)();
	int DoSomething(int i)
	{
		cout << "DoSomething" << endl;
		return 0
	}

	return 0;
}


typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

void main()
{
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
	(*f)();
}
#endif

#if 0
#include<set>

int main()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(2);

	for (auto& e : s)
	{
		cout << e << ' ';
	}
	cout << endl;

	s.erase(5);
	s.erase(3);
	for (auto& e : s)
	{
		cout << e << ' ';
	}
	cout << endl;

	int myints[] = { 12,75,10,32,20,25 };
	set<int> first(myints, myints + 3); 
	set<int> second(myints + 3, myints + 6);

	first.swap(second);
	for (auto& e : first)
	{
		cout << e << ' ';
	}
	cout << endl; 
	for (auto& e : second)
	{
		cout << e << ' ';
	}
	cout << endl;
	first.clear();
	second.clear();
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	string str1, str2;
	int s1 = str1.size();
	int s2 = str2.size();
	while (cin >> str1 >> str2)
	{
		map<char, int> ss1, ss2;
		for (int i = 0; i < s1; ++i)
		{
			ss1[str1[i]]++;
		}
		for (int j = 0; j < s2; ++j)
		{
			ss2[str2[j]]++;
		}
		for (int k = 'A'; k <= 'Z'; ++k)
		{
			if (k == 'Z')
			{
				cout << "Yes" << endl;
			}
			if (ss2[k] > ss1[k])
			{
				cout << "No" << endl;
				break;
			}
		}
	}
	return 0;
}
#endif

