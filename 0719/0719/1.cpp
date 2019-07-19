#include<iostream>
using namespace std;

#if 0
class A
{
public:
	int _a;
};
class B :virtual public A
{
public:
	int _b;
};
class C :virtual public A
{
public:
	int _c;
};
class D :public B, public C
{
public:
	int _d;
};
int main()
{
	//cout << sizeof(D) << endl;
	D d;
	d.B::_a = 1;
	d._b = 3;

	d.C::_a = 2;
	d._c = 4;
	
	d._d = 5;
	
	return 0;
}
#endif

#if 0
int main()
{
	char* ptr;
	char str[] = "abcdefg";
	ptr = str;
	ptr += 5;
	return 0;
}
#endif

#if 0
int main()
{
	int a[] = { 1,2,3,4,5 };
	int* p[] = { a,a + 1,a + 2,a + 3 };
	int** q = p;
	cout << *(p[0] + 1) + **(q + 2) << endl;
	return 0;

}
#endif

#include<stdio.h>
int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	return 0;
}