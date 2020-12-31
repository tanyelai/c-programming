#include <stdio.h>


int main()
{ 

long long int t; scanf("%lld", &t);

for(int i=0; i<t; i++)
{
    long long int n;
    scanf("%lld", &n);

    long long int des[n][n];
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<n; k++)
        {
            scanf("%lld", &des[j][k]);
        }
    }

    long long int con[n], col[n];
    for(int j=0; j<n; j++)
    {
        long long int y=0;
        for(int k=0; k<n; k++)
        {
            y=y+des[j][k];
        }
        con[j]=y;
    }

    for(int j=0; j<n; j++)
    {
        long long int z=0;
        for(int k=0; k<n; k++)
        {
            z=z+des[k][j];
        }
        col[j]=z;
    }

    for(int j=0; j<n-1; j++)
    {
        for(int k=0; k<n-j-1; k++)
        {
            if(con[k]>con[k+1])
            {
                long long int t=con[k+1];
                con[k+1]=con[k];
                con[k]=t;
            }
            if(col[k]>col[k+1])
            {
                long long int t=col[k+1];
                col[k+1]=col[k];
                col[k]=t;
            }
        }
    }

    int flag=0;
    for(int l=0; l<n; l++)
    {
        if(con[l]!=col[l])
            flag++;
    }

    if(flag==0)
        printf("Possible\n");
    else
        printf("Impossible\n");
}

return 0;
}
