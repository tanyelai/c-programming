#include <stdio.h>
#include <stdlib.h> //malloc içerir

int f(int *);
int g(int);
int main()
{
	int *p;
	int a=10;
	p=&a;
	printf("1.%d\n",*p);
	*p = 20;
	printf("2.%d\n",a);
	int *q = (int *) malloc (sizeof(int)*a);
	q[3] = 70;
	printf("3.%d\n",q[3]);
	f(&a);
	printf("4.%d\n",a);
	g(a);
	printf("5.%d\n",a);	
	
}
int g(int a){
	a = 90;
}

int f(int *a){
	*a = 80;
}
	
	
	
	

