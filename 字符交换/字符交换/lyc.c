#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
int my_strlen(const char* str)//Çó×Ö·û´®³¤¶Èº¯Êý
{
	int count = 0;
	assert(str);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse(char a[], int left, int right)//ÄæÐòº¯Êý
{
	while (left < right)
	{
		char tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}
char* reverse_string(char a[])//ÄæÐò×Ö·û´®
{
	int i = 0;
	int left = 0;
	int right = my_strlen(a) - 1;//ÄæÐòÕû¸ö×Ö·û´®
	reverse(a, left, right);
	//ÄæÐòÖð¸öµ¥´Ê
	while (a[i] != '\0')
	{
		left = i;
		while ((a[i] != '\0') && (a[i] != ' '))
		{
			i++;
		}
		right = i - 1;
		reverse(a, left, right);
		if (a[i] != '\0')
			i++;
	}
	return a;
}
int main()
{
	char a[] = "student a am i";
	reverse_string(a);
	printf("%s\n", a);
	system("pause");
	return 0;
}