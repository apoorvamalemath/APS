#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gettingSum(int n, int x,int y,int z)
{
  int i;
  int a[n+1];
  int p1,p2;
  memset(a, 0, (n+1)*sizeof(a[0]));

  for(i=0;i<n+1;i++)
    {
      if(i%x==0)
      a[i]=1;
    }

  //a[y]=1;
  p1=y;
  p2=0;
  for(i=0;i<n+1;i++)
    {

    	if((p1+p2)%y==0)
            a[p1]=a[p1]+a[p2];
	p1++;
	p2++;

    }


    p1=z;
    p2=0;
  for(i=0;i<n+1;i++)
    {
        if((p1+p2)%z==0)
            a[p1]=a[p1]+a[p2];
        p1++;
        p2++;

    }
    for(i=0;i<n+1;i++)
    printf("%d ",a[i]);


return a[n];
}

int main()
{
 int res=gettingSum(15,3,5,10);
 printf("\nANS %d\n",res);

 return 0;
}
