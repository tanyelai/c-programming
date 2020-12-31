#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int page_width,to_page,i,counter=0,counter2=0;
	scanf("%d\n%d",&page_width,&to_page);
	

	for ( i=1; i<=to_page; i++ )
	{
		if ( i%2 == 0 )
			counter++;
		
	}
	
	for ( i=page_width; i>to_page; i-- )
	{
		if ( i%2 == 0)
			counter2++;
					
	}
	
	counter = counter < counter2 ? counter : counter2;
	
	printf("%d",counter);
		
	return 0;
}
