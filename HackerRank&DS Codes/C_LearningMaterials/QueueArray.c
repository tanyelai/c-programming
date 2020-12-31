#include <stdio.h>
#include <stdlib.h>

int size=2,que=0,queHead=0,i;
int *arr=NULL;
void enque(int);
int deque();


int main()
{
	for (i=0;i<20;i++)
		enque(i*10);
		
	printf("Durum- Size: %d, Que: %d, QueHead %d ",size,que,queHead);
	
	for (i=0;i<13;i++)
		printf("%d ",deque());
		
	printf("Durum- Size: %d, Que: %d, QueHead %d ",size,que,queHead);
	
	for (i=0;i<20;i++)
		enque(i*10);
		
	printf("Durum- Size: %d, Que: %d, QueHead %d ",size,que,queHead);

	return 0;
}
	
void enque(int data)
{
	if (arr == NULL){
		arr=(int*)malloc(sizeof(int)*2);
	}
	
	else if (que >= size){
		int *tempArr=(int*)malloc(sizeof(int)*size*2);
		
		for (i=0;i<size;i++){
			tempArr[i] = arr[i]; 
		}
		size *= 2;
		free(arr);
		arr = tempArr;	
		free(tempArr);	
	}
	
	arr[que++] = data; 
	
}


int deque()
{
	if(arr == NULL){
		printf("Queue is empty");
		return -1;
	}
	
	if (que-queHead <= size/4){
		int *tempArr=(int*)malloc(sizeof(int)*(size/2));
		
		for(i=0; i<que-queHead; i++){
			tempArr[i] = arr[i+queHead];
		}
		
		que -= queHead;
		queHead=0;
		size /= 2;
		free(arr);
		arr = tempArr;
		free(tempArr);
	}

	return arr[queHead++];
	
}





































