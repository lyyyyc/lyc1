#include<iostream>
#include<vector>
#include<string>
using namespace std;


#if 0
int MostPublic(int a, int b)
{
	int k, p;
	for (k = 1; k <= a && k <= b; ++k)
	{
		if (a % k == 0 && b % k == 0)
		{
			p = k;
		}
	}
	return p;
}
int main()
{
	int a, n;
	cin >> n >> a;
	vector<int> b(n);
	int i = 0;
	while (cin >> b[i] && i < n)
	{
		if (a >= b[i])
		{
			a += b[i];
		}
		else
		{
			a += MostPublic(a, b[i]);
		}
		i++;
	}
	cout << a << endl;
	return 0;
}
#endif

class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "all" << endl;
	}
};
class Student:public Person
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
	Person Mike;
	Func(Mike);

	Student John;
	Func(John);

	return 0;
}
