

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