#include <stdio.h>
#include <stdlib.h>

int get_number(int,int,int);

int main()
{
	long long int t,n,m,s,i;
	scanf("%ld",&t);

	for(i=0; i<t; i++){
		scanf("%ld %ld %ld",&n,&m,&s);
		printf("%ld\n",get_number(n,m,s));
	}	

	
	return 0;
}
int get_number(int n,int m,int s)
{
	return (1+(s+m-2)%n);	
}
