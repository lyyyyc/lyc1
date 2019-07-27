#include<iostream>
#include<stdio.h>
using namespace std;

#if 0
int main()
{
	int m = 5;
	if (m++ > 5)
		cout << m << endl;
	cout << --m;
	return 0;
}
#endif

//²åÈëÅÅÐò
#if 0
void InsertSoft(int *array,int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];//´ý²åÈëÔªËØ
		int end = i - 1;
		while (end>=0&&key<array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	int array[] = { 3,5,2,9,1,7,6,0,8,4 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	InsertSoft(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}
#endif

//Ï£¶ûÅÅÐò
#if 0
void ShellSoft(int* array, int size)
{
	int gap = 3;
	while (gap > 0)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];//´ý²åÈëÔªËØ
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
		//gap=gap/3+1;
	}
}
void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	int array[] = { 3,5,2,9,1,7,6,0,8,4 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	ShellSoft(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}
#endif

//Ñ¡ÔñÅÅÐò
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void SelectSort(int *array,int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int maxPos = 0;
		for (int j = 1; j < size-i; ++j)
		{
			if (array[j] > array[maxPos])
			{
				maxPos = j;
			}
		}
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}
void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	int array[] = { 3,5,2,9,1,7,6,0,8,4 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	SelectSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}