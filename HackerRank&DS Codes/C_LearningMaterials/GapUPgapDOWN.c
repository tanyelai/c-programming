#include <stdio.h>
#define SIZE 100000
int main()
{
	int i,j,n,low[SIZE],high[SIZE],close[SIZE],sayi,GapUP=0,GapDOWN=0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&sayi);
		low[i]=sayi;
	}
	for(i=0; i<n; i++){
		scanf("%d",&sayi);
		high[i]=sayi;
	}
	for(i=0; i<n; i++){
		scanf("%d",&sayi);
		close[i]=sayi;
	}
	
	i=0;
		for(j=i+1; j<n; j++){
			if(high[j]<close[i])
				GapDOWN++;
			
			if(low[j]>close[i])
				GapUP++;
			
			i++;
		}
		printf("%d %d",GapUP,GapDOWN);
		
	return 0;	
	}
	
	


