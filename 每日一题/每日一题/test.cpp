

/*标题：组队竞赛 | 时间限制：1秒 | 内存限制：32768K 
牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.
现在要将这些选手进行组队,一 共组成n个队伍,即每个队伍3人.
牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.
输入描述： 
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值. 
输出描述： 
输出一个整数表示所有队伍的水平值总和最大值. 
示例1: 
输入 
2 
5 2 8 5 1 5 
输出 
10
*/

#if 0
#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
int main() {    
	// IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。    
	int n;    
	while (cin >> n){        
		long long sum = 0;        
		vector<int> a;        
		a.resize(3*n);        
		for (int i = 0; i < (3 * n); i++){            
			cin >> a[i];        
		}                
		/* 排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来*/        
		sort(a.begin(), a.end());        
		for (int i = n; i <= 3 * n - 2; i += 2) { 
			sum += a[i]; 
		}        
		cout << sum << endl;
	}
}
#endif

/*标题：删除公共字符 | 时间限制：1秒 | 内存限制：32768K 
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.” 
输入描述： 
每个测试输入包含2个字符串 
输出描述：
输出删除后的字符串 
示例1: 
输入 
They are students. 
aeiou 
输出 
Thy r stdnts.
*/
#if 0
#include<iostream> 
#include<string> 
using namespace std;

int main() {    
	// 注意这里不能使用cin接收，因为cin遇到空格就结束了。    
	// oj中IO输入字符串最好使用getline。    
	string str1,str2;    
	//cin>>str1;    
	//cin>>str2;    
	getline(cin, str1);    
	getline(cin, str2);        
	// 使用哈希映射思想先str2统计字符出现的次数    
	int hashtable[256] = {0};    
	for(size_t i = 0; i < str2.size(); ++i){        
		hashtable[str2[i]]++;    
	}        
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在    
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)    
	// 因为边遍历，边erase，容易出错。    
	string ret;    
	for(size_t i = 0; i < str1.size(); ++i){        
		if(hashtable[str1[i]] == 0)   
			ret += str1[i];    
	}        
	cout<<ret<<endl;    
	return 0; 
} 
#endif

/*标题：排序子序列 | 时间限制：1秒 | 内存限制：32768K 
牛牛定义排序子序列为一个数组中一段连续的子序列,
并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,
牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,
牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,
至少需要划分为2个排序子序列,所以输出 2 
输入描述： 
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。 
输出描述： 
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列 
示例1: 
输入 
6 
1 2 3 2 2 1
输出 
2
*/
#if 0
#include<iostream> 
#include<vector> 
using namespace std;

int main() {
	int n;
	cin >> n;
	// 注意这里多给了一个值，是处理越界的情况的比较
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	//读入数组    
	int i = 0;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n) {
		// 非递减子序列        
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
			// 非递增子序列        
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

/*标题：倒置字符串 | 时间限制：1秒 | 内存限制：32768K 
将一句话的单词进行倒置，标点不倒置。
比如 I like beijing. 经过函数后变为：beijing. like I
输入描述： 
每个测试输入包含1个测试用例： I like beijing. 
输入用例长度不超过100 
输出描述： 
依次输出倒置之后的字符串,以空格分割 
示例1: 
输入 I like beijing. 
输出 beijing. like I
*/
#if 0
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std;

int main() 
{
	string s;    
	// 注意这里要使用getline，cin>>s遇到空格就接收结束了    
	getline(cin, s);        
	// 翻转整个句子    
	reverse(s.begin(), s.end());    
	// 翻转单词    
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

/* 标题：字符串中找出连续最长的数字串 | 时间限制：1秒 | 内存限制：32768K 
读入一个字符串str，输出字符串str中的连续最长的数字串 
输入描述： 
个测试输入包含1个测试用例，一个字符串str，长度不超过255。 
输出描述： 
在一行内输出str中里连续最长的数字串。 
示例1: 
输入 
abcd12345ed125ss123456789 
输出 
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
		// 数字+=到cur        
		if(str[i]>='0' && str[i]<='9')        
		{            
			cur+=str[i];        
		}        
		else       
		{            
			// 找出更长的字符串，则更新字符串            
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

/*标题：数组中出现次数超过一半的数字 | 时间限制：1秒 | 内存限制：32768K | 语言限制：[Javascript_V8, Python, C++, Javascript, Php, C#, Java] 
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组 {1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出 0。 */

#if 0
//第一种
class Solution 
{
public:    
	int MoreThanHalfNum_Solution(vector<int> numbers) {        
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优        
		if(numbers.empty()) 
			return 0;                 
		sort(numbers.begin(),numbers.end()); 
		// 排序，取数组中间那个数        
		int middle = numbers[numbers.size()/2];                 
		int count=0; // 出现次数        
		for(int i=0;i<numbers.size();++i)        
		{            
			if(numbers[i]==middle) ++count;        
		}                 
		return (count>numbers.size()/2) ? middle :  0;    
	} 
};

//第二种
class Solution 
{
public:    
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.empty()) 
			return 0;                 
	// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1        
		int result = numbers[0];        
		int times = 1; 
		// 次数                 
		for(int i=1;i<numbers.size();++i)        
		{            
			if(times == 0)            
			{                
				// 更新result的值为当前元素，并置次数为1                
				result = numbers[i];  times = 1;            
			}            
			else if(numbers[i] == result)            
			{                
				++times; 
				// 相同则加1            
			}            
			else            
			{                
				--times; 
				// 不同则减1                           
			}        
		}                 
		// 判断result是否符合条件，即出现次数大于数组长度的一半        
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

/*标题：计算糖果 | 时间限制：1秒 | 内存限制：32768K 
A,B,C三个人是好朋友,每个人手里都有一些糖果,
我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息： 
A - B, B - C, A + B, B + C. 这四个数值.
每个字母代表每个人所拥有的糖果数. 
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。
这里保证最多只有一组整数A,B,C满足所 有题设条件。 
输入描述： 
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，
用空格隔开。 范围均在-30到30之间(闭区间)。 
输出描述：
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，
用空格隔开，行末无空格。 如果不存在 这样的整数A，B，C，
则输出No 
示例1: 
输入 
1 -2 3 4 
输出 
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

/*标题：进制转换 | 时间限制：1秒 | 内存限制：32768K 
给定一个十进制数M，以及需要转换的进制数N。
将十进制数M转化为N进制数 
输入描述： 
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。 
输出描述： 
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，
则对应的数字规则参考16进制（比如，10 用A表示，等等） 
示例1: 
输入 
7 2 
输出 
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

	//如果是负数，则转成正数，并标记一下 
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	// 按进制换算成对应的字符添加到s
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

/*标题：统计回文 | 时间限制：1秒 | 内存限制：32768K 
“回文串”是一个正读和反读都一样的字符串，
比如“level”或者“noon”等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，
生日的时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。
你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。
如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文 
* 在第一个字母‘a’之后: "abba" 是回文 
* 在字母‘b’之后: "abba" 是回文 
* 在第二个字母'a'之后 "abab" 不是回文 
所以满足条件的答案为2 
输入描述： 
每组输入数据共两行。
第一行为字符串A
第二行为字符串B字符串长度均小于100且只包含小写字母 
输出描述： 
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数 
示例1: 
输入 
aba 
b 
输出 
2
*/

#if 0
#include<iostream> 
#include<string> 
using namespace std;

// 判断是否是回文 
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
		// 将字符串2插入到字符串1的每个位置，再判断是否是回文        
		string str = str1;        
		str.insert(i, str2);        
		if(IsCircleText(str))            
			++count;    
	}        
	cout<<count<<endl;    
	return 0; 
}
#endif

/*标题：连续最大和 | 时间限制：1秒 | 内存限制：32768K 
一个数组有 N 个元素，求连续子数组的最大和。
例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
输入描述： 
输入为两行。 第一行一个整数n(1 <= n <= 100000)，
表示一共有n个元素第二行为n个数，
即每个元素,每个整数都在32位int范围内。以空格分隔。 
输出描述： 
所有连续子数组中和最大的值。 
示例1: 
输入 
3 -1 2 1 
输出 
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
		// 计算到num[i]的子数组的最大和       
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

/*标题：不要二 | 时间限制：1秒 | 内存限制：32768K 
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，
网格的列编号为0~W-1。每个格子至多可以放一 块蛋糕，
任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。 
输入描述： 
每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000) 
输出描述： 
输出一个最多可以放的蛋糕数
示例1:
输入 
3 2 
输出 
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
				// 标记不能放蛋糕的位置                
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

/* 标题：把字符串转换成整数 | 时间限制：1秒 | 内存限制：32768K | 语言限制：[Javascript_V8, Python, C++, Javascript, Php, C#, Java] 
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
但是string不符合数字要求时返回0)，
要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0。 
输入描述： 
输入一个字符串,包括数字字母符号,可以为空 
输出描述： 
如果是合法的数值表达则返回该数字，否则返回0 
示例1: 
输入 
+2147483647 
1a33 
输出 
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
			//处理负号        
		{            
			symbol = -1;            
			str[0] = '0'; 
			//这里是字符'0',不是0        
		}        
		else if(str[0] == '+') 
			//处理正号        
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

/*标题：Fibonacci数列 | 时间限制：1秒 | 内存限制：32768K 
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一 个N，
你想让其变为一个Fibonacci数，
每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。 
输入描述： 
输入为一个正整数N(1 ≤ N ≤ 1,000,000) 
输出描述： 
输出一个最小的步数变为Fibonacci数" 
示例1: 
输入 
15 
输出 
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
		//找到比N小且距离N最近的数，求出距离        
		if(f < N)             
			l = N-f;        
		else        
		{            
			//找到比N大且距离N最近的数，求出距离            
			r = f - N;            
			break;        
		}    
	} 
	//取最小距离    
	if (l > r)
		cout << r << endl;
	else
		cout << l << endl;
	return 0; 
}
#endif

/*标题：合法括号序列判断 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，
请返回一个bool值代表它是否为一个合法的括号串。
一个合法的括号串定义为：
1.只包括括号字符；2.左括号和右括号一一对应
测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false*/

#if 0
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
#endif

/*标题：两种排序方法 | 时间限制：1秒 | 内存限制：32768K 
考拉有n个字符串字符串，任意两个字符串长度都是不同的。
考拉最近学习到有两种字符串的排序方法： 
1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，
考拉要忙着吃树叶，所以需要你来帮忙验 证。 
输入描述： 
输入第一行为字符串个数n(n ≤ 100) 接下来的n行,每行一个字符串,
字符串长度均小于100，均由小写字母组成 
输出描述： 
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
如果根据长度排列而不是字典序排列输出"lengths",
如果两种方式都符合输出"both"，否则输出"none" 
示例1: 
输入 
3 
a 
aa 
bbb 
输出 
both
*/

#if 0
#include<iostream> 
#include<vector> 
#include<string> 
using namespace std;

int main() 
{
	int n; 
	cin >> n; 
	vector<string> v; 
	v.resize(n); 
	for (auto& str : v)     
		cin >> str;
	bool lenSym = true, lexSym = true; 
	// 这里要注意从i=1开始遍历，前后比较，比较长度 
	for(size_t i = 1; i < v.size(); ++i) 
	{     
		if(v[i-1].size() >= v[i].size())     
		{         
			lenSym = false;         
			break;     
		} 
	} 
	//比较ASCII码 
	for(size_t i = 1; i < v.size(); ++i) 
	{     
		if(v[i-1] >= v[i])     
		{         
			lexSym = false;         
			break;     
		} 
	}      
	if (lenSym&& lexSym)  
		cout<<"both"<<endl; 
	else if (!lenSym && lexSym)     
		cout<<"lexicographically"<<endl; 
	else if (lenSym && !lexSym)    
		cout<<"lengths"<<endl; 
	else if (!lenSym&&!lexSym)    
		cout<<"none"<<endl;
	return 0;
}
#endif

/*标题：求最小公倍数 | 时间限制：1秒 | 内存限制：32768K 
正整数A和正整数B的最小公倍数是指能被A和B整除的最小的正整数值，
设计一个算法，求输入A和B的最小公倍数。
输入描述： 
输入两个正整数A和B。
输出描述： 
输出A和B的最小公倍数。
*/

#if 0
#include<iostream> 
using namespace std;
int gcd(int a, int b) 
{ 
	int r; 
	while(r = a%b)
	{     
		a = b;     
		b = r; 
	} 
	return b;
} 
int main()
{ 
	int a, b; 
	while (cin >> a >> b) 
	{ 
		cout << a * b / gcd(a, b) << endl; 
	} 
	return 0; 
}
#endif

/*标题：另类加法 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值
测试样例：
1,2
返回：
3
*/

#if 0
class UnusualAdd {
public: 
	int addAB(int A, int B) 
	{
		int sum = 0, carry = 0; 
		while (B != 0) 
		{ 
			//对应位的和  
			sum = A^B;
			//对应位和的进位，既然是进位，就要整体左移一位   
			carry = (A&B)<<1;
			A=sum;
			B=carry; 
		} 
		return sum; 
	} 
};
#endif

/*标题：201301 JAVA 题目2-3级 | 时间限制：1秒 | 内存限制：32768K 
请编写一个函数（允许增加子函数），
计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，
要求不能走回头路，
即：只能往右和往下走，不能往左和往上走。
输入描述： 
输入两个正整数
输出描述： 
返回结果
示例1: 
输入
2 
2
输出
6
*/

#if 0
#include<iostream> 
using namespace std; 
int pathNum(int n,int m) 
{ 
	if(n > 1 && m > 1) 
		//b情况，如果n,m都大于1，那么走到[n][m]格子的右下角只有两条路径，    
		//<1>: 从[n - 1][m]格子的右下角向下走，到达    
		//<2>: 从[n][m - 1]格子的右下角向右走，到达 
		//递归   
		return pathNum(n-1,m) + pathNum(n,m-1); 
	else if(((n >= 1)&&(m == 1))||((n == 1)&&(m >= 1)))
		// a情况，如果n或者m为1，则只有一行或者一列，
		//从左上角走到右下角的路径数为n + m 
		//终止条件   
		return n + m; 
	else
		//格子为0时， 路径为0   
		return 0; 
} 
int main() 
{
	int n,m;
	while(cin>>n>>m)
	{ 
		cout<<pathNum(n,m)<<endl; 
	} 
	return 0; 
} 
#endif

/*标题：井字棋 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，
其中元素为1的代表是当前玩家的棋子，
为0表示没有棋子，为-1代 表是对方玩家的棋子。
测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：
true*/

#if 0
class Board
{
public:
	bool CheckWon(vector<vector<int>>board)
	{
		int row = board.size();
		int i, j, sum;
		
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum += board[i][j];
			}
			if (sum == row)
			{
				return true;
			}
		}
		
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum = 0;
				sum += board[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}
		
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}
		
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		return false;
	}
};
#endif

/*标题：密码强度等级 | 时间限制：1秒 | 内存限制：32768K 
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度:
       5 分: 小于等于4 个字符
       10 分: 5 到7 字符
       25 分: 大于等于8 个字符
二、字母:
       0 分: 没有字母
       10 分: 全都是小（大）写字母
       20 分: 大小写混合字母
三、数字:
       0 分: 没有数字
       10 分: 1 个数字
       20 分: 大于1 个数字
四、符号:
       0 分: 没有符号
       10 分: 1 个符号
       25 分: 大于1 个符号
五、奖励:
       2 分: 字母和数字
       3 分: 字母、数字和符号
       5 分: 大小写字母、数字和符号
最后的评分标准:
       >= 90: 非常安全
       >= 80: 安全（Secure）
       >= 70: 非常强
       >= 60: 强（Strong）
       >= 50: 一般（Average）
       >= 25: 弱（Weak）
       >= 0:  非常弱
对应输出为：
	VERY_WEAK,
	WEAK,    
	AVERAGE,    
	STRONG,     
	VERY_STRONG,
	SECURE,     
	NOWCODER
	VERY_SECURE 
请根据输入的密码字符串，进行安全评定。
注：
       字母：a-z, A-Z
       数字：0-9
       符号包含如下：      (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
       !"#$%&'()*+,-./      (ASCII码：x21~0x2F)
       :;<=>?@                (ASCII<=><=><=><=><=>码：x3A~0x40)
       [\]^_`                     (ASCII码：x5B~0x60)
       {|}~                        (ASCII码：x7B~0x7E)
接口描述：
 Input Param       
	String pPasswordStr:    密码，以字符串方式存放。
 Return Value   
	根据规则评定的安全等级。
 
 
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr) 
{     
	//在这里实现功能
	return null;
}

输入描述：
输入一个string的密码
输出描述：
输出密码等级
示例1 :
输入
38$@NoNoNo
输出
VERY_SECURE */

#if 0
#include<iostream> 
#include<string> 
using namespace std; 

int numChar(string str, int k) 
{    
	//根据ASCII码判断字母大小写    
	int small = 0;    
	int big = 0;    
	for (int i = 0; i < k; i++)    
	{        
		if (str[i] >= 65 && str[i] <= 90)         
			big++;       
		else if (str[i] >= 97 && str[i] <= 122)   
			small++;   
	}  
	if ((small + big) == 0)    
		return 0;   
	else if (small == k || big == k)     
		return 10;  
	else if (small > 0 && big > 0) 
		return 20;    
	return 0; 
} 

int numNumber(string str, int k)
{    
	//根据ASCII码判断数字个数，减去字符‘0’之后在0~9之间的即为数字 
	int num = 0;   
	for (int i = 0; i < k; i++)  
	{       
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)    
			num++;  
	}   
	if (num == 0)  
		return 0;   
	else if (num == 1)    
		return 10;    
	else        
		return 20; 
} 

int numSymbal(string str, int k) 
{   
	int num = 0;  
	for (int i = 0; i < k; i++) 
	{       
		//除去字母，数字，其它都为符号    
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)        
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))   
			num++;   
	}   
	if (num == 0)   
		return 0;   
	else if (num == 1)    
		return 10;  
	else     
		return 25; 
} 

int main()
{   
	string str;   
	while (cin >> str)  
	{    
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;    
		int k = str.size();    
		if (k <= 4)      
			sum1 = 5;      
		else if (k >= 8)        
			sum1 = 25;  
		else        
			sum1 = 10;    
		sum2 = numChar(str, k);  
		sum3 = numNumber(str, k);    
		sum4 = numSymbal(str, k);    
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))      
		{         
			if (sum2 == 10)   
				sum5 = 3;      
			else  sum5 = 5; 
		}   
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)     
			sum5 = 2;    
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)  
			cout << "VERY_SECURE" << endl;    
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)   
			cout << "SECURE" << endl;    
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)    
			cout << "VERY_STRONG" << endl;   
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)    
			cout << "STRONG" << endl;   
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)   
			cout << "AVERAGE" << endl;   
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)       
			cout << "WEAK" << endl;     
		else           
			cout << "VERY_WEAK" << endl;   
	}  
	return 0; 
} 
#endif

/*标题：最近公共祖先 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，
根结点编号为1。现在有两个结点 a，b。请设计一个算法，
求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。
注意这里结点本身也可认为是其祖先。
测试样例：
2，3
返回：
1
*/

#if 0
#include<iostream>
using namespace std;
class LCA
{
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
			{
				a /= 2;
			}
			if (b > a)
			{
				b /= 2;
			}
		}
		return a;
	}
};
int main()
{
	LCA a;
	cout << a.getLCA(11, 80) << endl;
	return 0;
}
#endif

/*标题：求最大连续bit数 | 时间限制：1秒 | 内存限制：32768K 
功能: 求一个byte数字对应的二进制数字中1的最大连续数，
例如3的二进制为00000011，最大连续2个1    
输入: 
一个byte型的数字    
输出: 
无     
返回: 
对应的二进制数字中1的最大连续数
输入描述： 
输入一个byte数字
输出描述： 
输出转成二进制之后连续1的个数
示例1: 
输入 
3
输出 
2
*/

#if 0
#include<iostream>	
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count=0, maxcount=0;
		while (n)
		{
			if (n & 1)
			{
				count++;
				maxcount=max(count, maxcount);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}
#endif

/*标题：二进制插入 | 时间限制：3秒 | 内存限制：32768K | 语言限制：[Python, C++, C#, Java] 
有两个32位整数n和m，请编写算法,
将m的二进制数位插入到n的二进制的第j到第i位,
其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，
请返回操作后的数，保证n的第j到第i位均为零，
且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：
1100
*/

#if 0
#include<iostream>
using namespace std;
class BinInsert 
{ 
public:
	int binInsert(int n, int m, int i, int j)
	{ 
		m <<= j; 
		return n | m; 
	} 
};
int main()
{
	BinInsert b;
	cout<<b.binInsert(1024, 19, 6, 2)<<endl;
	return 0;
}
#endif

/*标题：查找组成一个偶数最接近的两个素数 | 时间限制：1秒 | 内存限制：32768K 
任意一个偶数（大于2）都可以由2个素数组成，
组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对 
输入描述： 
输入一个偶数
输出描述： 
输出两个素数
示例1: 
输入 
20
输出
7 
13*/

#include<iostream> 
#include<algorithm> 
using namespace std; 
//判断素数 
bool isPrime(int num) 
{  
	int tmp = sqrt(num);
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除 
	for (int i = 2; i <= tmp; i++)   
	{    
		if (num %i == 0)        
			return false;
	}
	return true; 
}
int main()
{
	int num;   
	int half; 
	int i;    
	while (cin >> num) 
	 {
		half = num / 2; 
		//从中间向两边找    
		for (i = half; i > 0; i--)     
		{         
			if (isPrime(i) && isPrime(num - i))      
				break;      
		}
		cout << i << endl << num - i << endl;
	 }   
	return 0;
}