#include<stdio.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

void pascals(int n,int k)
{
    int a[100][100];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    ///print
        for(i=0;i<n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    pascals(5,2);
    return 0;
}
