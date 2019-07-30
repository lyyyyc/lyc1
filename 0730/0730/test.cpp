/*#include<iostream>
using namespace std;

int main()
{
	int i;
	int n;
	while (cin >> n)
	{
		if (n < 10)
		{
			cout << n;
		}	
		else
		{
			int a = n / 10;
			int b = n - a * 10;
			i = a + b;
			if (i >= 10)
			{
				while (i >= 10)
				{
					a = i / 10;
					b = i - a * 10;
					i = a + b;
				}
			}
			cout << i;
		}
	}
	cout << endl;
	return 0;
}*/

#include<iostream>
using namespace std;

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		double a = r * 2* 3.14;
		if (n > a)
		{
			cout << "No" << " ";
		}
		else {
			cout << "Yes" << " ";
		}
	}
	cout << endl;
	return 0;
}