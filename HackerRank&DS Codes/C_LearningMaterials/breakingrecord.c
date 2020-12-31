#include <stdio.h>
#include <stdlib.h>

int max_counter(int,int *);
int min_counter(int,int *);


int main()
{
	
	int n,max=0,min=0;
	scanf("%d",&n);
	
	int *arr= (int *) malloc (n* sizeof(int));
	for (int i=0; i<n; i++)
		scanf("%d",arr+i);
	
	max= max_counter(n,arr);
	min= min_counter(n,arr);
	printf("%d %d",max,min);
	
	
	return 0;
}

int max_counter(int n, int *arr)
{
	int counter=0;
	int temp=arr[0];
	
	for (int i=1; i<n; i++){
		if (*(arr+i) > temp){
			temp = *(arr+i);
			counter++;
		}
	}
	return counter;
}

int min_counter(int n, int *arr)
{
	int counter2=0;
	int temp2=arr[0];
	
	for (int i=1; i<n; i++){
		if (*(arr+i) < temp2){
			temp2 = *(arr+i);
			counter2++;
		}
	}
	return counter2;
}

