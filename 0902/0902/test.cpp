#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;

#if 0
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int a;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.pop();

	s.push(3);
	s.pop();
}
#endif

#if 0
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
		{
			return 0;
		}
		int left = 0;
		int right = rotateArray.size() - 1;
		while (left < right)
		{
			if (rotateArray[left] < rotateArray[right])
			{
				return rotateArray[left];
			}
			int mid = left + (right - left) / 2;
			if (rotateArray[left] < rotateArray[mid])
			{
				left = mid + 1;
			}
			else if (rotateArray[mid] < rotateArray[right])
			{
				right = mid;
			}
			else
			{
				++left;
			}
		}
		return rotateArray[left];
	}
};

int main()
{
	Solution s;
	vector<int> v = {2,3,4,5,1};
	s.minNumberInRotateArray(v);
	return 0;
}
#endif

#if 0
class Solution {
public:
	int  NumberOf1(int n) {
		return bitset<32>(n).count();
	}
};
int main()
{
	Solution s;
	cout<<s.NumberOf1(1234567)<<endl;
	return 0;
}
#endif

#if 0
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead)
		{
			return nullptr;
		}
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		while (cur)
		{
			ListNode* nHead = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nHead;
		}
		pHead->next = nullptr;
		return pre;
	}
};
int main()
{
	Solution s;
	ListNode* pHead = 0;
	
	cout<<s.ReverseList(pHead)<<endl;
	return 0;
}
#endif

class Solution {
public:
	bool isPalindrome(string s1) {
		string s2;
		for (auto& i : s1)
		{
			if (isdigit(i))
			{
				s2.push_back(i);
			}
			else if (isupper(i))
			{
				s2.push_back(i);
			}
			else if (islower(i))
			{
				s2.push_back(i - 'a' + 'A');
			}
		}
		s1 = s2;
		reverse(s1.begin(), s1.end());
		return s1 == s2;
	}
};
int main()
{
	Solution s;
	string str = { "Abcd cbA!" };
	s.isPalindrome(str);
	return 0;
}