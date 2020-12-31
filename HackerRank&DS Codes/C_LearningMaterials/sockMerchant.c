#include <stdio.h>
#include <stdlib.h>


int sock_merchant(int , int *);

int main()
{
	int n;
	scanf("%d",&n);
	
	int *arr= (int *) malloc (n*sizeof(int));
	for (int i=0; i<n; i++)
		scanf("%d",arr+i);
	
	sock_merchant(n,arr);
	
	return 0;
}

int sock_merchant(int n,int *arr)
{
	
	int matches=0;
	int colors[100];
	for (int j=0; j<n; j++){
	
		if (colors[arr[j]] == 1){
			matches++;
			colors[arr[j]]=0;		
		}
		else {
			colors[arr[j]]=1;
		}
			
	}
	printf("%d",matches);

	return matches;
	
}
