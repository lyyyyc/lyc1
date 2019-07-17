#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,3,3,1,4,6,4,5,5 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	/*找出单独的数，就将数组中的每个数全都取异或运算，
	如：arr[1]={1,3,3,1,4}
	01^11=10，再用这个结果10^11=01,01^01=00,000^100=100=4
   独的数结果就为1
	（1）a=a^b    c^a相当于c^(a^b)
	（2）自己异或自己两次相当于没有异或，还是自己。*/
	for (i = 1; i < len; i++)
	{
		arr[0] = arr[0] ^ arr[i];
	}
	printf("单独的数是:%d", arr[0]);
	system("pause");
	return 0;
}
