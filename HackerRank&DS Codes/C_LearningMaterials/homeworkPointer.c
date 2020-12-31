#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main()
{
	unsigned int values[SIZE]={2,4,6,8,10};//a
	unsigned int *vPtr;//b
	
	int i;
	for(i=0; i<SIZE; i++)
		printf("c.%d ",values[i]); //c
		
	vPtr = values;
	//vptr == values now //d
	
	for(i=0; i<SIZE; i++)
		printf("e.%d ",*(vPtr+i)); //e
		
	for(i=0; i<SIZE; i++)
		printf("f.%d ",*(values+i)); //f
		
	for(i=0; i<SIZE; i++)
		printf("g.%d ",vPtr[i]); //g
		
		
	printf("%d %d %d %d",values[4],*(values+4),vPtr[4],*(vPtr+4)); // refering to 5th element //h
 
	printf("%d ",(vPtr+3));  //i 
	printf("%d ",*(vPtr+3)); //i
	
	*vPtr = values[4];                  //j
	vPtr -= 4;							//j						
	printf("%d %d ",(vPtr),*(vPtr));	//j


	
	return 0;
}
