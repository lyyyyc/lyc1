#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* reverse_string(char * string){
	assert(string != NULL);
	if (*string != '\0'){
		string++;
		reverse_string(string);
		printf("%c", *(string - 1));
	}
	return string;
}
int main(){
	char arr[] = "abcdefg";
	reverse_string(arr);
	system("pause");
	return 0;
}