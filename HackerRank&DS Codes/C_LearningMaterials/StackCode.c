#include <stdio.h>
#include <stdlib.h>

int *arr;
int height = 2;
int top=0;

int pop()
{
	if(top<=height/4){
		int *tempArr = (int*)malloc(sizeof(int)*(height/2));
		int i;
		for (i=0;i<height/2; i++)
			tempArr[i] = arr[i];
		free(arr);
		arr = tempArr;
		height /= 2;
	}
	if (top <= 0){
		printf("Stack is empty,please do not try popping more. ");
		return -1;
	}
		return arr[--top];
}

void push(int data)
{
	if(top >= height){
		int *tempArr = (int*)malloc(sizeof(int)*height*2);
		int i;
		for (i=0;i<height; i++)
			tempArr[i] = arr[i];
		free(arr);
		arr = tempArr;
		height *= 2;
	}
	arr[top++] = data;	
}

void print()
{
	int i;
	for (i=0; i<top; i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	arr = (int*)malloc(sizeof(int)*2);
	push(10);
	push(20);
	push(40);
	push(30);
	push(50);
	print();
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("boyut: %d ",height);
	printf("popped %d",pop());
	printf("boyut: %d ",height);
	printf("popped %d",pop());
	printf("popped %d",pop());
	print();
	push(40);
	push(50);
	push(80);
	push(70);
	push(50);
	push(10);
	push(20);
	printf("boyut: %d ",height);
	push(80);
	push(150);
	print();
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	printf("popped %d",pop());
	
	printf("boyut: %d ",height);
	return 0;

}
