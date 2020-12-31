#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){ 
      
    char s[100];
    scanf("%s",s);
	long long int i,n,lenth,b,c,h,count=0,count1=0; 
    scanf("%lld",&n);
   
    lenth=strlen(s);
    b=n/lenth;
    c=n%lenth;
 
    for(i=0;i<lenth;i++){
        if(s[i]=='a'){
            count++;
        }
        
    }
     
  	h=count*b;
  
    for( i=0;i<c;i++){
       if(s[i]=='a'){
            count1++;
        }
    }
    h=h+count1;
    printf("%lld",h);
    
    return 0;
}

