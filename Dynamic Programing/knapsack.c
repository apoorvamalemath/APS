/* knapscak problem, using dynamic programming approach
*/

#include<stdio.h>
#include<stdlib.h>

//macro that gives max of two numbers
#define max(x, y) (((x) > (y)) ? (x) : (y))

int main()
{

    int n,mw;

    printf("Enter total number of items : ");
    scanf("%d",&n);

    int w[n+1],val[n+1];

    printf("Enter the max capacity of the bag : ");
    scanf("%d",&mw);

    printf("Enter the Weight array");
    int i,j ;
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);

    printf("Enter the value array\n");
    for(i=1;i<=n;i++)
        scanf("%d",&val[i]);

    int result[n+1][mw+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=mw;j++)
        {
            //all initial components are zero
            if(i==0 || j==0){
                result[i][j]=0;
                continue;
            }

            //if item has more weight than capacity of bag then retain old weight
            if(j-w[i]<0)
                result[i][j]=result[i-1][j];

            else
            {
               result[i][j] = max(result[i-1][j],result[i-1][j-w[i]]+val[i]);
            }

        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=mw;j++)
            printf("%d\t",result[i][j]);
        printf("\n");
    }

    return 0;
}
