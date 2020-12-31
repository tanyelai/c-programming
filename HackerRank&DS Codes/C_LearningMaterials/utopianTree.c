#include <stdio.h>

int main()
{
	int total_case, period,i,j,height=1,res=0;
	scanf("%d",&total_case);
	
	for (i=0; i<total_case; i++){
		scanf("%d",&period);
		
		for (j=1; j<=period; j++){
			
			if (j%2 == 0)
				height++;
			else
				height *= 2;
		
		}
		printf("%d\n",height);
		
		height=1;
	}
	
	
	return 0;
}
