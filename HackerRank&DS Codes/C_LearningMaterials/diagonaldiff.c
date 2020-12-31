#include <stdio.h>
#include <stdlib.h>

int diagonalDifftoR(int **,int);
int diagonalDifftoL(int **,int);

int main()
{
	int n,sonuc=0,i,j;
	int sayi;
	printf("Enter your matrix's width:");
	scanf("%d",&n);
	int **arr;
	arr = (int **) malloc (n* sizeof(int*));
	for (i=0; i<n; i++){
		arr[i]= (int*) malloc (n* sizeof(int));
	}
	
	printf("Enter your elements: ");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			scanf("%d",&sayi);
			arr[i][j]= sayi;
		}
	}
	
	sonuc = ( diagonalDifftoL(arr,n) - diagonalDifftoR(arr,n) );
	if (sonuc < 0)
	{
		sonuc *= -1;
		printf("%d",sonuc);
	}
	else 
	{
		printf("%d",sonuc);
	}
	
	return 0;
}

int diagonalDifftoR(int **arr,int n)
	{
	int i,x=0;
	for (i=0; i<n; i++){
		x = x + arr[i][i];
	}	

	return x;
}

int diagonalDifftoL(int **arr,int n)
{
	int i,y=0;
	for (i=0; i<n; i++){
		y = y + arr[i][n-1-i];
}	
	
	return y;
}









