#include<stdio.h>

int binomialCoeff(int n,int k)
{
    if(k==0||k==n)
        return 1;
    else
        return (binomialCoeff(n-1,k)+binomialCoeff(n-1,k-1));
}

int main()
{
    printf("%d\n",binomialCoeff(5,3));
}
