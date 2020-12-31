#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long int i,n,h,wallPoints[100000],lengths[100000],max,r,totalHeight[100000];
    double ans;
    scanf("%ld %ld",&n,&h);
    
        for(i=0; i<n; i++)
            scanf("%ld",wallPoints+i);

        for(i=0; i<n; i++)
            scanf("%ld",lengths+i);
    
    for(i=0; i<n; i++){
        
		ans=0;
		ans= wallPoints[i] + (((double)lengths[i]*0.25) - ((double)lengths[i]/2));
		ans -= h;
		r = (int)ceil(ans);
       	totalHeight[i]= r;
	   
	}
	    
    	max=totalHeight[0];
            for(i=1; i<n; i++){
			
           		if (totalHeight[i] > max)
                	max = totalHeight[i];
            
 			}
    	if (max == -1)
    		max = 0;
    	printf("%ld",max);
   
    return 0;
}
