#include <stdio.h>
#include <stdlib.h>


int main()
{
	
	int start_point,end_point,appTree_loc,orTree_loc,apple_num,orange_num;
	int counterApp=0, counterOr=0;
	
	scanf("%d %d",&start_point,&end_point);
	scanf("%d %d",&appTree_loc,&orTree_loc);
	scanf("%d %d",&apple_num,&orange_num);
	
	int *arrApp = (int *) malloc (apple_num*sizeof(int));
	int *arrOr = (int *) malloc (orange_num*sizeof(int));
	
	for (int i=0; i < apple_num; i++)
		scanf("%d ",arrApp+i);
	
	for (int i=0; i < orange_num; i++)
		scanf("%d ",arrOr+i);
	
	
	for (int i=0; i < apple_num; i++){
		if (arrApp[i]+appTree_loc <= end_point && arrApp[i]+appTree_loc >= start_point)
			counterApp += 1;
	}
	
	for (int i=0; i < orange_num; i++){
		if (arrOr[i]+orTree_loc <= end_point && arrOr[i]+orTree_loc >= start_point)
			counterOr += 1;
	}
	
	
	printf("%d\n%d",counterApp,counterOr);
	
	
	return 0;
}
