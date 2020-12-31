#include <stdio.h>

int main()
{
	long int i,j,q,n,a,b,temp=0;
	scanf("%ld",&q);
	
	for(i=0; i<q; i++){
		scanf("%ld",&n);
		temp=0
		for(j=0; j<n; j++){	
			
			scanf("%ld %ld",&a,&b);
			b += temp;
			
			if(n>1 && a<b){
				temp = b-a;
			}
			else
				temp=0;
			
			if(a>=b && j==(n-1)){
				printf("0\n");
			}
			else if(a<b && j ==(n-1))
				printf("1\n");
		
		}
		
		
	}
	
	
	return 0;
}
