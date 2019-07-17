#include<stdio.h>
#include<stdlib.h>

int main(){
	int A, B, C, D, E;
	for (A = 0; A <= 5; ++A) {
		for (B = 0; B <= 5; ++B) {
			for (C = 0; C <= 5; ++C) {
				for (D = 0; D <= 5; ++D) {
					for (E = 0; E <= 5; ++E) {
						if((A==3)+(B==2)==1&&
							(B==2)+(E==4)==1&&
							(C==1)+(D==2)==1&&
							(C==5)+(D==3)==1&&
							(A == 1) + (E == 4) == 1){
							if (A * B * C * D * E == 120) {
								printf("A是第%d\nB是第%d\nC是第%d\nD是第%d\nE是第%d\n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}