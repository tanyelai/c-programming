#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr_width,can_jump,i,max=0;
	scanf("%d %d",&arr_width,&can_jump);
	
	int *arr=(int*) malloc (arr_width*sizeof(int));
	for (i=0; i<arr_width; i++)
		scanf("%d",arr+i);
		
	for(i=0; i<arr_width; i++){
		if(max < *(arr+i))
			max=*(arr+i);
	}
		
		max = max > can_jump ? max-can_jump : 0;
		printf("%d",max);
		
	return 0;
}
/*if(max > can_jump){
			max = max-can_jump;
			printf("%d",max);
		}
		else
			printf("0");
			*/
