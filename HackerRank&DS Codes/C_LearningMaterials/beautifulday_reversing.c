#include <stdio.h>
#include <stdlib.h>

int beautifulDays(int,int,int);

int main()
{
	
	int bottom,top,divisible_num,res=0;
	scanf("%d %d %d",&bottom,&top,&divisible_num);
	
	res=beautifulDays(bottom,top,divisible_num);
	
	printf("%d",res);
	
	return 0;
}
int beautifulDays(int bottom, int top, int divisible_num) {
	int num,count=0,gn;
	int quo, newNum = 0, x = 0;
	for (int x = bottom; x <= top ; x++)
	{
		num = x;
		newNum = 0;
		//For reversing no
		while (num != 0)
		{
			quo = num % 10;
			newNum = 10 * newNum + quo;
			num = num / 10;
		}
		gn = abs(x- newNum);
		if (gn%divisible_num==0)
		{
			count++;
		}
	}
	return count;
}
