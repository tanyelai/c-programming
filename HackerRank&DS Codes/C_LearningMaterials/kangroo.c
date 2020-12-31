#include <stdio.h>
#define DISTANCE 100000000

int dist_calc(int x1,int v1,int x2,int v2)
{
	int temp=0;
	for (int i=0 ; i<DISTANCE; i++){
		if ( x1 + v1*i == x2 + v2*i )
			temp = 1;
	}
	return temp;
}

int main()
{
	
	int x1,v1,x2,v2;
	
	scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
	
	if (dist_calc(x1,v1 ,x2 ,v2 ) == 1)
		printf("YES");
	else 
		printf("NO");

	
	
	return 0;
	
}
