#include <stdio.h>
#include <math.h>
// ÇALIÞMIYORRRR
int main()
{
	long long int num= pow(2,1000);
	long long int temp,sum=0;
	
	while(num > 0){
		temp = num%10;
		sum += temp;
		num /= 10;
	}
	printf("%lld",sum);
	
	
	return 0;
}
