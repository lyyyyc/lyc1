#include<iostream>
using namespace std;

#if 0
int f(int n)
{
	static int i= 1;
	if (n >= 5)
	{
		return n;
	}
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	cout << f(1) << endl;
	return 0;
}
#endif


int getTotalCount(int n)
{
	
	if (n<=2)
		return 1;
	return getTotalCount(n - 1) + getTotalCount(n - 2);
}
int main()
{
	int n;
	cin >> n;
	int i = getTotalCount(n);
	cout << i<< endl;
	return 0;
}