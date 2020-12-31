#include <stdio.h>

int main()
{
    int n,i,j,t;
    scanf("%d",&n);
    int a = n;
    char space = ' ';
    char hash = '#';
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < a - 1; j++)
            printf("%c", space);
        
        a--;
        
        for(t = 0; t < i + 1; t++)
            printf("%c", hash);
            
        printf("\n");
    }
    return 0;
}
