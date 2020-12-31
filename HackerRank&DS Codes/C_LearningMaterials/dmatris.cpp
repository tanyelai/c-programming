#include<stdio.h>

int main(){
	int k=1,i,j,matr[50][50];
	
	for(i=0; i<50; i++){
		for(j=0; j<50; j++){
	    	matr[i][j]	= k;
		    k++;
		
		}
		k += 51;
	}
	
	for(i=0; i<50; i++){
		for(j=0; j<50; j++){
			printf("%d ",matr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
