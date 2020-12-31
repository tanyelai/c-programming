#include <stdio.h>

int main()
{
	int t,n,i,j,temp=0,counter=0;
	scanf("%d",&t);
	
	for(i=0; i<t; i++){
		scanf("%d",&n);
		int flag=n;
		while(n > 0){
				
			temp = n%10;
			if (temp != 0){
			
			if ( flag%temp == 0)
				counter++;					
			}

			n /= 10;
		
		}
		printf("%d\n",counter);
		counter=0;
	}
	
	return 0;
}
