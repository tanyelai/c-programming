#include <stdio.h>
#include <stdlib.h>

// EASY YAZIYOR ÇOK SAÐLAM SORU

int main()
{
	int arr_width;
	scanf("%d",&arr_width);
	
	int *arr= (int *) malloc (arr_width*sizeof(int));
	for (int i =0; i<arr_width; i++)
		scanf("%d",arr+i);
		
	int id[] = {0,0,0,0,0};
	for (int i=0; i<arr_width; i++)
		id[arr[i]-1]++;
		
	int max=0;
	for (int i=0; i<5; i++){
		if (id[max] < id[i])
			max = i;
	}
	
	printf("%d",max+1);
	
	

	return 0;
}

	
	
	
	
	
	






