#include <stdio.h>
#include <stdlib.h>



int main()
{
	int total_loop,arr_width,threshold,i,j,counter=0;
	scanf("%d",&total_loop);
		
	for(i=0; i<total_loop; i++){
		
		scanf("%d %d",&arr_width,&threshold);
		
		int *arr=(int*) malloc (arr_width*sizeof(int));
		for (j=0; j<arr_width; j++)
			scanf("%d",arr+j);
			
		
		for (j=0; j<arr_width; j++)
		{
			if ( *(arr+j) <= 0)
				counter++;	
		}		
		
		if ( counter < threshold )
			printf("YES\n");
		else
			printf("NO\n");
		
		counter=0;
	}
	

	return 0;
}
