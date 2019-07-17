#include<stdio.h>
#include<stdlib.h>
int main(){ 
	int i ;
	for (i = 1; i <10; ++i){
		int j ;		
		for (j = 1; j < i+1; ++j){
			printf("%d*%d=%d\t", j,i, i*j);
		}		
		printf("\n"); 
	}	system("pause");	
	return 0; 
}
