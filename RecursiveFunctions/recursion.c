#include <stdio.h>
int factorial(int);
int getPower(int, int); //for positive exponent
int countDigits(int);
int fibonacci(int);

int main(){

int x, y, res, c;
printf("choose the function you want to go through: \n1)Factorial\n2)getPower\
\n3)countDigits\n4)Fibonacci\nchoice:");
scanf("%d", &c);

switch (c)
{
case 1:
    printf("Enter a number: ");
    scanf("%d", &x);
    res = factorial(x);
    printf("Result: %d", res);
    break;

case 2:
    printf("Enter the base and power: ");
    scanf("%d %d", &x, &y);
    res = getPower(x, y);
    printf("Result: %d", res);
    break;

case 3:
    printf("Enter a number: ");
    scanf("%d", &x);
    res = countDigits(x);
    printf("Result: %d", res);
    break;

case 4:
    printf("Enter a number: ");
    scanf("%d", &x);
    res = fibonacci(x);
    printf("Result: %d", res);
    break;

default:
    break;
}

return 0;
}

int factorial(int n){
    if(n<=1)
        return 1;
    return n * factorial(n-1);
}

int getPower(int x, int y){

    if (y>0)
        return x * getPower(x, y-1);

    else
        return 1;
}

int countDigits(int n){
    if (n/10 == 0)
        return 1;
    
    return 1+countDigits(n/10);
}

int fibonacci(int n){
    if (n<=3 && n>1)
        return 1;
    else if (n==1)
        return 0;
        
    return fibonacci(n-1) + fibonacci(n-2);
}