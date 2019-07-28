#include<iostream>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
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

//插入排序
#if 0
void InsertSoft(int *array,int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];//待插入元素
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

//希尔排序
#if 0
void ShellSoft(int* array, int size)
{
	int gap = 3;
	while (gap > 0)
	{
		for (int i = gap; i < size; ++i)
		{
			int key = array[i];//待插入元素
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

//选择排序
#if 0
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
#endif

//堆排序
#if 0
void HeapSort(int* array, int size)
{

}
#endif

//冒泡排序
#if 0
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void BubbleSort(int* array, int size)
{
	int end = size - 1;
	while (end > 0)
	{
		for (int i = end - 1; i > +0; i--)
		{
			if (array[end] < array[i])
			{
				Swap(&array[end], &array[i]);
			}
			end--;
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
	BubbleSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}
#endif


#if 0
void InsertSoft(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];//待插入元素
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
//快速排序
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
//三数取中法
int GeiMiddleIndex(int* array, int left, int right)
{
	int mid = left+((right-left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
		{
			return left;
		}
		else if (array[mid] > array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (array[mid] > array[left])
		{
			return left;
		}
		else if (array[mid] < array[right-1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
}
//hoare版本
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GeiMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right-1];
	while (begin<end)
	{
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		if (begin != end)
		{
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right - 1)
	{
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}
//挖坑法
int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GeiMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];
	while (begin < end)
	{
		//从前往后找比基准值大的元素，找到后填充end位置的坑
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		//填充end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}
		//从后往前找比基准值小的元素，找到后填充begin位置的坑
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		//填充begin位置的坑
		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}
//前后指针
int Partion3(int* array, int left, int right)
{
	int cur = left;
	int pre = left - 1;
	int mid = GeiMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];
	while (cur<right)
	{
		if (array[cur] < array[right - 1]&&++pre!=cur)
		{
			Swap(&array[pre], &array[cur]);
		}
		cur++;
	}
	if (pre < right)
	{
		Swap(&array[++pre], &array[right - 1]);
	}
	return pre;
}
void QuickSort(int* array, int left,int right)
{
	if (right - left < 16)
	{
		InsertSoft(array, right - left);
	}
	else
	{
		//按照基准值将区间分割成左右两部分
		//左侧小于基准值，右侧大于基准值
		int div = Partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div+1, right);
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
	int array[] = { 3,4,2,9,1,7,6,0,8,5 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	QuickSort(array,0, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}
#endif

//归并排序
void MergeData(int* array, int left, int mid, int right,int *tmp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
		{
			tmp[index++] = array[begin1++];
		}
		else
		{
			tmp[index++] = array[begin2++];
		}
	}
	while (begin1 < end1)
	{
		tmp[index++] = array[begin1++];
	}
	while (begin2 < end2)
	{
		tmp[index++] = array[begin2++];
	}
}
void _MergeSort(int *array,int left,int right,int *tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid,tmp);
		_MergeSort(array, mid, right,tmp);
		MergeData(array, left, mid, right,tmp);
		memcpy(array+left, tmp+left, sizeof(int) * (right - left));
	}
}
void MergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);
	if (NULL == tmp)
	{
		assert(0);
		return;
	}
	_MergeSort(array, 0,size,tmp);
	free(tmp);
}
void MergeSortCir(int* array, int size)//循环归并
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	if (NULL == tmp)
	{
		assert(0);
		return;
	}
	int gap = 1;
	while (gap<size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid >= size)
			{
				mid = size;
			}
			if (right >= size)
			{
				right = size;
			}
			MergeData(array, left, mid, right, tmp);
		}
		memcpy(array, tmp, sizeof(int) * size);
		gap *= 2;
	}
	free(tmp);
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
	int array[] = { 3,4,2,9,1,7,6,0,8,5 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	MergeSortCir(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	return 0;
}