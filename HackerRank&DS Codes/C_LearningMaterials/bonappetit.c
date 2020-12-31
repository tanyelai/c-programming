#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int n,k,b;
	scanf("%d %d", &n, &k);
	
	int *arr= (int *) malloc (n*sizeof(int));
	for (int i = 0; i<n; i++)
		scanf("%d",arr+i);
		
	scanf("%d",&b);
	
	int sum=0;
	for (int j=0; j<n; j++)
		sum+=arr[j];
	sum = (sum - arr[k])/2;
	
		if (sum == b)
			printf("Bon Appetit");
		else if (sum < b){
			b -= sum;
			printf("%d",b);
		}
	

	
	
	return 0;
}
