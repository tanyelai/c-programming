#include <stdio.h>
#include <string.h>

int main()
{
	int height[26],i,j,res=0,max=0;
	for(i=97; i<=122; i++)
		scanf("%d",&height[i]);
		
  	char letter[10];
  	fflush(stdin);
  	scanf("%s",letter);

	for(i=97; i<=122; i++){
		for(j=0; j<strlen(letter); j++){
		
			if (i == letter[j] && max < height[i])
			max = height[i];
			
		}
	}
	res= max*strlen(letter);
	
	printf("%d",res);

	return 0;
}
