#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int query;
	scanf("%d",&query);
	
	int id[3];
	for (int j=0; j<query; j++){
		for (int i=0; i<3; i++)
			scanf("%d ",&id[i]);
	
	int x,y,z;
	x=id[0];
	y=id[1];
	z=id[2];
	

    if (fabs(x-z) - fabs(y-z) > 0){
        printf("Cat B\n");
    } else if (fabs(x-z) - fabs(y-z) < 0){
        printf("Cat A\n");
    } else {
        printf("Mouse C\n");
    }

}
	
	return 0;
}
