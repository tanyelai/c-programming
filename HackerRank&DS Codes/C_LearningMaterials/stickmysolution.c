#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int n,*arr,i,f,max=0;
	scanf("%d",&n);
	
	arr= (int*) malloc (n*sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d",arr+i);
		if(arr[i]>max)
			max=arr[i];
	}
		
		
	int min=1001,counter=0;
	do{
		counter=0;
		min=1001;
		for(i=0; i<n; i++){
			if( (arr[i]<min && arr[i] != 0) )
				min=arr[i];
		}

		for(i=0; i<n; i++){
			if( arr[i] != 0 ){
				arr[i] -= min;
				counter++;			
			}		
		}

		if(counter)
        printf("%d\n",counter);
		
		max -= min;
			
	}while(max!=0);
	
	return 0;
}
