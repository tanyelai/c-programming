#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k,*arr,i,energy=100;
	scanf("%d %d",&n,&k);
	
	arr=(int*) malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d",arr+i);
	

	for (i=0; i<n ; i++){
		
		if (arr[(i+k)%n]==0)
			energy--;
		if (arr[(i+k)%n]==1)
			energy-=3;
		i += k-1;
	}
		
	printf("%d",energy);
		
	return 0;
}
