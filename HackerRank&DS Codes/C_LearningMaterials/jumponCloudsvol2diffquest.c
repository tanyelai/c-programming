#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,*arr,i,counter=0;
	scanf("%d",&n);
	
	arr=(int*) malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d",arr+i);
	
	for(i=1; i<n; i++){
		
		if (arr[i] == 0 && arr[i+1] != 0)
			counter++;
		else if (arr[i+1] != 1){
			counter++;
			i++;
		}
		else 
			counter;
			
	}
	printf("%d",counter);
	
		
	return 0;
}
