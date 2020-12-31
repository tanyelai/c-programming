#include <stdio.h>
#include <stdlib.h>

int main(){
	long long stack[100005],max[100005],x; 
	long long N,top=-1; 
	long long q,i; 
	scanf("%lld",&N);
	
 
	for(i=0;i<N;i++ )
     {    
         scanf("%lld",&q);

         switch(q)
         {
             case 1: scanf(" %lld",&x);
                 top++;
                     if(max[top-1]<x)
                     {
                     max[top]=x;
                     }
                 else max[top]=max[top-1];
                     stack[top]=x;
                     break;
             case 2: 
                     top--;
                     break;
             case 3: 
                     printf("%lld\n",max[top]);
                     break;
         }
     }
	
	return 0;	
}
