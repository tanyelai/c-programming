#include <stdio.h>

int main() {
    int n,i,j,max=0,cnt;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        {
        cnt=0;
        
        for(j=i;j<n;j++)
            {
            if(a[i]==a[j])
                cnt++;
             }
       
        if(cnt>max)
            max=cnt;
    }
    printf("%d",n-max);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
