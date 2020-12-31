#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
int main() 

{  
	int i,j,k;  	
	char a;  
	for (i=10;i>0;i--)  
    {
	    printf("Geri Sayim:%d\n",i);   
	    a = getch();   
	    if (a==27)    
	{
	    printf("Cikis\n");    
		break;   
	}   
    else   
	{    
			a = getch();    
			printf("Bastiginiz ok tusu:%d\n",a);   
}  
    	sleep(1);   
		system("cls");   
} 	
	printf("BOOOOM!");  
	return 0; 
} 
