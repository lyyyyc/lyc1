#include<iostream>
using namespace std;
struct Test
{
	Test(int) {}
	Test() {}
	void fun() {}
};
void main(void)
{
	Test a(1);
	a.fun();
	Test b();
	b.fun();
}
