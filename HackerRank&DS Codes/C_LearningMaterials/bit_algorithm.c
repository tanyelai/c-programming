#include <stdio.h>
#include <stdlib.h>
#include <>

void compare_bits(int n, int k, int *arr)
{
	int max_and=0, max_or=0, max_xor=0;
	int temp= 0;
	
	for (int i=0; i<k; i++){
		for (int j=(i+1); j<n; j++){
			
			temp= arr[i]&arr[j];
			if (temp > max_and && temp < k)
				max_and = temp;
			
			temp= arr[i]|arr[j];
			if (temp > max_or && temp < k)
				max_or = temp;
			
			temp= arr[i]^arr[j];
			if (temp > max_xor && temp < k)
				max_xor = temp;
			
		}
	}
	free(temp);
	printf("%d\n%d\n%d",max_and,max_or,max_xor);

}

int main()
{
	int n,k;
	
	printf("Enter your limit of array ");
	scanf("%d",&n);
	printf("Enter your comparing limit of function ");
	scanf("%d",&k);
	
	int *arr =(int *) malloc (n*sizeof(int));
	
	for (int i = 0; i<n; i++){
		arr[i] = (i+1);
	}

	compare_bits(n,k,arr);
		
	return 0;
}
