#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr_width,sayac=0,sum=0;
	scanf("%d",&arr_width);
	
	int *arr= (int *) malloc(arr_width* sizeof(int));
	for (int i=0; i<arr_width; i++)
		scanf("%d",arr+i);
		
	int ron_day,ron_month;
	scanf("%d %d",&ron_day,&ron_month);
	
	
	for (int i=0; i<arr_width; i++){		
		sum = arr[i];
		
		for (int j=i+1; j<ron_month+i; j++){
			sum += arr[j];
	
		}
			if (sum == ron_day)
			sayac++;
		
	}
	printf("%d",sayac);
	
	return 0;
	
}
