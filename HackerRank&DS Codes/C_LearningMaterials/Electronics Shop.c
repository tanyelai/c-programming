#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int budget,keyboard_width,drive_width,i, max=0;
	scanf("%d %d %d",&budget,&keyboard_width,&drive_width);
	
	
	int *keyboard= (int *) malloc (keyboard_width*sizeof(int));
	for(i=0; i<keyboard_width; i++)
		scanf("%d",keyboard+i);
	
	int *drive= (int *) malloc (drive_width*sizeof(int));
	for(i=0; i<drive_width; i++)
		scanf("%d",drive+i);
		
	
	for(i=0; i<keyboard_width; i++){
		
		
		for(int j=0; j<drive_width; j++){
			
			if(keyboard[i] + drive[j] <= budget && keyboard[i] + drive[j] > max){
				max = keyboard[i] + drive[j];
			}			
		}
	}
		if(max == 0)
			printf("-1");
		else
			printf("%d",max);
	
	return 0;
}
