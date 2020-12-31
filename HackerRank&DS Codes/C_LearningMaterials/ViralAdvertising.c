#include <stdio.h>

int main()
{
	int total_day,total_like=2,member = 5;;
	scanf("%d",&total_day);
	
	for (int i=1; i<total_day; i++){
		member= (member/2)*3; 
		total_like += member/2;
		
	}	
	printf("%d",total_like);
	

	return 0;
}
