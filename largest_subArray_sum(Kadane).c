#include<stdio.h>

int larSum(int a[100],int n)
{
    int max=0,tmax=0;
    int i;
    for(i=0;i<8;i++)
    {
        tmax=tmax+a[i];
        if(tmax<0)
            tmax=0;
        else if(tmax>max)
            max=tmax;
    }
    return max;
}


int main()
{
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    printf("%d\n",larSum(a,8));
}
