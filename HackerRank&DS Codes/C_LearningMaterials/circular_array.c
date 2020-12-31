#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr_width,qua_query,subs_num,subs_res,i,j,temp=0;
	scanf("%d %d %d",&arr_width,&qua_query,&subs_num);
	
	int *arr= (int*) malloc (arr_width*sizeof(int));
	for(i=0; i<arr_width; i++)
		scanf("%d",arr+i);

		
	for(i=0; i< qua_query  ; i++){
		
		temp= arr[arr_width-1];
		for(j=arr_width-1; j>0; j--){
			arr[j] = arr[j-1];
		
	}
		arr[0] = temp;
		
	}
	for(i=0; i<subs_num; i++){
		scanf("%d",&subs_res);
		printf("%d\n",arr[subs_res]);
	}	

	return 0;
}
