#include<stdio.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}

int binomialCoeff(int n,int k)
{
    int c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=min(i,k);j>0;j--)
            c[j]=c[j]+c[j-1];
    return c[k];
}

int main()
{
    printf("%d\n",binomialCoeff(5,3));
}
