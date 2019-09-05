#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE* pFile = fopen("myfile.txt", "w");
	if (pFile)
	{
		fputs("abcde", pFile);
		fclose(pFile);
	}
	return 0;
}