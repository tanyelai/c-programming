#include <stdio.h>

int main()
{
	unsigned long long temp;
	int n,i;
	scanf("%d",&n);
	
	temp=1;
	for (i=2; i<=n; i++){
	
		temp *= i;
		
	}
	printf("%llu",temp);
	
	return 0;
}
