

/*���⣺��Ӿ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
ţţ�ٰ���һ�α�̱���,�μӱ�������3*n��ѡ��,ÿ��ѡ�ֶ���һ��ˮƽֵa_i.
����Ҫ����Щѡ�ֽ������,һ �����n������,��ÿ������3��.
ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
����:
һ������������Ա��ˮƽֵ�ֱ���3,3,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3,2,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1,5,2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���,ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ:
���ţţ��6����Ա���ֵ���������
�������Ϊ:
team1:{1,2,5}, team2:{5,5,8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
���������Ϊ:
team1:{2,5,8}, team2:{1,5,5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
û�б��ܺ�Ϊ10����ķ���,�������10.
���������� 
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)
�ڶ��а���3*n������a_i(1 �� a_i �� 10^9),��ʾÿ������ѡ�ֵ�ˮƽֵ. 
��������� 
���һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ. 
ʾ��1: 
���� 
2 
5 2 8 5 1 5 
��� 
10
*/

#if 0
#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
int main() {    
	// IO��OJ���ܻ��ж��������������������Ҫ������������������������    
	int n;    
	while (cin >> n){        
		long long sum = 0;        
		vector<int> a;        
		a.resize(3*n);        
		for (int i = 0; i < (3 * n); i++){            
			cin >> a[i];        
		}                
		/* ����Ȼ��ȡ�±�Ϊ3n - 2��3n - 4 ��3n - 4... n+2��nλ�õ�Ԫ���ۼӼ��ɣ��൱�±�Ϊ[0,n-1]��n������ÿ�������ߵ�����ʣ�µ�2����������Ϊһ�飬���ֵ�����ұߵ������δ�����м�ֵ��������ǰ�����δ��ֵ������*/        
		sort(a.begin(), a.end());        
		for (int i = n; i <= 3 * n - 2; i += 2) { 
			sum += a[i]; 
		}        
		cout << sum << endl;
	}
}
#endif

/*���⣺ɾ�������ַ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou����
��ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.�� 
���������� 
ÿ�������������2���ַ��� 
���������
���ɾ������ַ��� 
ʾ��1: 
���� 
They are students. 
aeiou 
��� 
Thy r stdnts.
*/
#if 0
#include<iostream> 
#include<string> 
using namespace std;

int main() {    
	// ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ����ˡ�    
	// oj��IO�����ַ������ʹ��getline��    
	string str1,str2;    
	//cin>>str1;    
	//cin>>str2;    
	getline(cin, str1);    
	getline(cin, str2);        
	// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���    
	int hashtable[256] = {0};    
	for(size_t i = 0; i < str2.size(); ++i){        
		hashtable[str2[i]]++;    
	}        
	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���    
	// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)    
	// ��Ϊ�߱�������erase�����׳���    
	string ret;    
	for(size_t i = 0; i < str1.size(); ++i){        
		if(hashtable[str1[i]] == 0)   
			ret += str1[i];    
	}        
	cout<<ret<<endl;    
	return 0; 
} 
#endif

/*���⣺���������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
ţţ��������������Ϊһ��������һ��������������,
��������������Ƿǵ������߷ǵݼ�����ġ�
ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,
ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,
ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,
������Ҫ����Ϊ2������������,������� 2 
���������� 
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)
�ڶ��а���n������A_i(1 �� A_i �� 10^9),��ʾ����A��ÿ�����֡� 
��������� 
���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ����������� 
ʾ��1: 
���� 
6 
1 2 3 2 2 1
��� 
2
*/
#if 0
#include<iostream> 
#include<vector> 
using namespace std;

int main() {
	int n;
	cin >> n;
	// ע����������һ��ֵ���Ǵ���Խ�������ıȽ�
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	//��������    
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n) {
		// �ǵݼ�������        
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else
			// �ǵ���������        
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

/*���⣺�����ַ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
��һ�仰�ĵ��ʽ��е��ã���㲻���á�
���� I like beijing. �����������Ϊ��beijing. like I
���������� 
ÿ�������������1������������ I like beijing. 
�����������Ȳ�����100 
��������� 
�����������֮����ַ���,�Կո�ָ� 
ʾ��1: 
���� I like beijing. 
��� beijing. like I
*/
#if 0
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std;

int main() 
{
	string s;    
	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����    
	getline(cin, s);        
	// ��ת��������    
	reverse(s.begin(), s.end());    
	// ��ת����    
	auto start = s.begin();    
	while (start != s.end())    
	{        
		auto end = start;        
		while (end != s.end() && *end != ' ')            
			end++;
	reverse(start, end);
	if (end != s.end())           
		start = end + 1;        
	else            
		start = end;
}
	cout << s << endl;
	return 0; 
}
#endif

/* ���⣺�ַ������ҳ�����������ִ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
����һ���ַ���str������ַ���str�е�����������ִ� 
���������� 
�������������1������������һ���ַ���str�����Ȳ�����255�� 
��������� 
��һ�������str��������������ִ��� 
ʾ��1: 
���� 
abcd12345ed125ss123456789 
��� 
123456789
*/

#if 0
#include<iostream> 
#include<string> 
using namespace std; 
int main() {    
	string str,res,cur;    
	cin>>str;    
	for(int i=0;i<=str.length();i++)    
	{        
		// ����+=��cur        
		if(str[i]>='0' && str[i]<='9')        
		{            
			cur+=str[i];        
		}        
		else       
		{            
			// �ҳ��������ַ�����������ַ���            
			if(res.size() < cur.size())                
				res=cur;            
			else                
				cur.clear();        
		}    
	}    
	cout<<res;    
	return 0; 
} 
#endif

/*���⣺�����г��ִ�������һ������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ�[Javascript_V8, Python, C++, Javascript, Php, C#, Java] 
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������ {1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
�������������� 0�� */

#if 0
//��һ��
class Solution 
{
public:    
	int MoreThanHalfNum_Solution(vector<int> numbers) {        
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������        
		if(numbers.empty()) 
			return 0;                 
		sort(numbers.begin(),numbers.end()); 
		// ����ȡ�����м��Ǹ���        
		int middle = numbers[numbers.size()/2];                 
		int count=0; // ���ִ���        
		for(int i=0;i<numbers.size();++i)        
		{            
			if(numbers[i]==middle) ++count;        
		}                 
		return (count>numbers.size()/2) ? middle :  0;    
	} 
};

//�ڶ���
class Solution 
{
public:    
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.empty()) 
			return 0;                 
	// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1        
		int result = numbers[0];        
		int times = 1; 
		// ����                 
		for(int i=1;i<numbers.size();++i)        
		{            
			if(times == 0)            
			{                
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1                
				result = numbers[i];  times = 1;            
			}            
			else if(numbers[i] == result)            
			{                
				++times; 
				// ��ͬ���1            
			}            
			else            
			{                
				--times; 
				// ��ͬ���1                           
			}        
		}                 
		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��        
		times = 0;        
		for(int i=0;i<numbers.size();++i)        
		{            
			if(numbers[i] == result) 
				++times;        
		}                 
		return (times > numbers.size()/2) ? result : 0;    
	} 
};
#endif

/*���⣺�����ǹ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,
���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ�� 
A - B, B - C, A + B, B + C. ���ĸ���ֵ.
ÿ����ĸ����ÿ������ӵ�е��ǹ���. 
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C��
���ﱣ֤���ֻ��һ������A,B,C������ ������������ 
���������� 
����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C��
�ÿո������ ��Χ����-30��30֮��(������)�� 
���������
���Ϊһ�У�����������������A��B��C��˳�����A��B��C��
�ÿո��������ĩ�޿ո� ��������� ����������A��B��C��
�����No 
ʾ��1: 
���� 
1 -2 3 4 
��� 
2 1 3
*/

#if 0
#include<iostream> 
using namespace std;

int main() 
{ 
	int a, b, c, d;    
	cin >> a >> b >> c >> d;    
	int A = (a + c) / 2;   
	int C = (d - b) / 2;   
	int B1 = (c - a) / 2;   
	int B2 = (b + d) / 2;   
	if (B1 != B2)        
		cout << "No";    
	else        
		cout << A << " " << B1 << " " << C;        
	return 0; 
}
#endif

/*���⣺����ת�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
����һ��ʮ������M���Լ���Ҫת���Ľ�����N��
��ʮ������Mת��ΪN������ 
���������� 
����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������ 
��������� 
Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9��
���Ӧ�����ֹ���ο�16���ƣ����磬10 ��A��ʾ���ȵȣ� 
ʾ��1: 
���� 
7 2 
��� 
111
*/


#if 0
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
 	cin >> m >> n;
	bool flag = false;

	//����Ǹ�������ת�������������һ�� 
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s
	while (m)
	{
		s += table[m % n];
		m /= n;
	}
	if (flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

/*���⣺ͳ�ƻ��� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
�����Ĵ�����һ�������ͷ�����һ�����ַ�����
���硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ���
���յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ���
����ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ��� 
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ��� 
* ����ĸ��b��֮��: "abba" �ǻ��� 
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ��� 
�������������Ĵ�Ϊ2 
���������� 
ÿ���������ݹ����С�
��һ��Ϊ�ַ���A
�ڶ���Ϊ�ַ���B�ַ������Ⱦ�С��100��ֻ����Сд��ĸ 
��������� 
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ����� 
ʾ��1: 
���� 
aba 
b 
��� 
2
*/

#if 0
#include<iostream> 
#include<string> 
using namespace std;

// �ж��Ƿ��ǻ��� 
bool IsCircleText(const string& s) 
{    
	size_t begin = 0;    
	size_t end = s.size()-1;    
	while(begin < end)    
	{        
		if(s[begin] != s[end])            
			return false;                
		++begin;        
		--end;    
	}        
	return true; 
}

int main() 
{
	string str1, str2;    
	getline(cin, str1);    
	getline(cin, str2); 
	size_t count = 0;    
	for (size_t i = 0; i <= str1.size(); ++i) 
	{        
		// ���ַ���2���뵽�ַ���1��ÿ��λ�ã����ж��Ƿ��ǻ���        
		string str = str1;        
		str.insert(i, str2);        
		if(IsCircleText(str))            
			++count;    
	}        
	cout<<count<<endl;    
	return 0; 
}
#endif

/*���⣺�������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
һ�������� N ��Ԫ�أ�����������������͡�
���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3 
���������� 
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)��
��ʾһ����n��Ԫ�صڶ���Ϊn������
��ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ��� 
��������� 
���������������к�����ֵ�� 
ʾ��1: 
���� 
3 -1 2 1 
��� 
3
*/


#if 0
#include <iostream> 
#include<vector> 
using namespace std;

int main() 
{
	int size;    
	cin >> size;    
	vector<int> nums(size);    
	for (size_t i = 0; i < size; ++i)        
		cin >> nums[i];        
	int result = nums[0];    
	int sum1 = 0, sum2 = 0;    
	for (int i = 0; i < nums.size(); i++) 
	{       
		// ���㵽num[i]�������������       
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];       
		if(sum2 > result)           
			result = sum2; 
		if(sum2 < 0)           
			sum2 = 0;                
		sum1 = sum2;    
	}        
	cout<<result<<endl;         
	return 0; 
} 
#endif

/*���⣺��Ҫ�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��
������б��Ϊ0~W-1��ÿ������������Է�һ �鵰�⣬
�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������ 
���������� 
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000) 
��������� 
���һ�������Էŵĵ�����
ʾ��1:
���� 
3 2 
��� 
4
*/

#if 0
#include<iostream> 
#include<vector> 
using namespace std; 
int main() 
{    
	int w,h,res = 0;    
	cin >> w >> h;    
	vector<vector<int>> a;    
	a.resize(w);    
	for(auto& e : a)        
		e.resize(h, 1);        
	for(int i=0;i<w;i++)    
	{        
		for(int j=0;j<h;j++)        
		{            
			if(a[i][j]==1)            
			{                
				res++;                
				// ��ǲ��ܷŵ����λ��                
				if((i+2)<w)                    
					a[i+2][j] = 0;                                
				if((j+2)<h)                    
					a[i][j+2] = 0;            
			}        
		}    
	}    
	cout << res << endl;
	return 0; 
} 
#endif

/* ���⣺���ַ���ת�������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ�[Javascript_V8, Python, C++, Javascript, Php, C#, Java] 
��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
����string����������Ҫ��ʱ����0)��
Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0�� 
���������� 
����һ���ַ���,����������ĸ����,����Ϊ�� 
��������� 
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0 
ʾ��1: 
���� 
+2147483647 
1a33 
��� 
2147483647 
0
*/

#if 0
class Solution 
{
public:    
	int StrToInt(string str) 
	{
		if (str.empty())            
			return 0;            
		int symbol = 1;        
		if (str[0] == '-') 
			//������        
		{            
			symbol = -1;            
			str[0] = '0'; 
			//�������ַ�'0',����0        
		}        
		else if(str[0] == '+') 
			//��������        
		{            
			symbol = 1;            
			str[0] = '0';       
		}            
		int sum = 0;        
		for(int i=0;i<str.size();++i)        
		{            
			if(str[i] < '0' || str[i] > '9')            
			{                
				sum = 0;                
				break;            
			}                          
			sum = sum *10 + str[i] - '0';                     
		}        
		return symbol * sum;    
	} 
}; 
#endif

/*���⣺Fibonacci���� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ ��N��
���������Ϊһ��Fibonacci����
ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci���� 
���������� 
����Ϊһ��������N(1 �� N �� 1,000,000) 
��������� 
���һ����С�Ĳ�����ΪFibonacci��" 
ʾ��1: 
���� 
15 
��� 
2
*/

#if 0
#include <iostream> 
using namespace std; 
int main()
{    
	int N, f, l = 0,r = 0,f0 = 0,f1 = 1;    
	cin >> N;    
	while(1)
	{        
		f = f0 + f1;        
		f0 = f1;        
		f1 = f;        
		//�ҵ���NС�Ҿ���N����������������        
		if(f < N)             
			l = N-f;        
		else        
		{            
			//�ҵ���N���Ҿ���N����������������            
			r = f - N;            
			break;        
		}    
	} 
	//ȡ��С����    
	if (l > r)
		cout << r << endl;
	else
		cout << l << endl;
	return 0; 
}
#endif

/*���⣺�Ϸ����������ж� | ʱ�����ƣ�3�� | �ڴ����ƣ�32768K | �������ƣ�[Python, C++, C#, Java] 
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n��
�뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
һ���Ϸ������Ŵ�����Ϊ��
1.ֻ���������ַ���2.�����ź�������һһ��Ӧ
����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
����������
"()(()()",7
���أ�false*/

class Parenthesis 
{
public:    
	bool chkParenthesis(string A, int n) 
	{     
		// write code here        
		stack<char> sc;        
		for (auto ele : A) 
		{            
			switch (ele) 
			{                
				case '(':                    
				sc.push(ele);                    
				break;                
				case ')':                    
				{                        
					if (sc.empty() || sc.top() != '(')                            
						return false;                        
					else                            
					sc.pop();                    
				}                    
				break;             
				default:                 
				return false;            
			}        
		}        
		return true;    
	} 
}; 