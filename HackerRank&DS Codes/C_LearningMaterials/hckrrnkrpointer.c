#include <stdio.h>


void sumofints(int *a, int *b, int A){
	A= (*a)+(*b);
	printf("%d\n",A);
}

void diffofints(int *a, int *b, int B){
	B= (*a)-(*b);
	if ( B < 0) {
		B *= -1;
		printf("%d",B);
	}
	else{
		printf("%d",B);
	}
}

int main()
{
	int a,b,A,B;
	scanf("%d %d",&a,&b);
	sumofints(&a,&b,A);
	diffofints(&a,&b,B);
	
	
	return 0 ;
	
}
