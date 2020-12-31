#include <stdio.h>
#include <stdlib.h>



int main()
{
	
	int arr1_num,arr2_num;
	scanf("%d %d",&arr1_num,&arr2_num);
	
	int *arr1= (int *) malloc (arr1_num* sizeof(int));
	int *arr2= (int *) malloc (arr2_num* sizeof(int));
	
	for (int i=0; i < arr1_num; i++)
		scanf("%d",arr1+i);
		
	for (int i=0; i < arr2_num; i++)
		scanf("%d",arr2+i)
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
