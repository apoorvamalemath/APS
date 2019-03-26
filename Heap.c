#include<stdio.h>

void bottomUpHeap(int H[], int n)
{
    int k,v,heap;

    for(int i=n/2 ;i>=1; i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(!heap && ((2*k)<=n))
        {//atleast one child
            
            //1 or 2 children
            int j=2*k;
            if(j<n)
            {
                if(H[j+1]>H[j])
                    j=j+1;
            }

            if(v>=H[j])
               heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }

        }

        H[k]=v;
    }
}

int main()
{
     int H[50]={0,3,2,7,9,11,5,6};
    //0th index is wasted to use 2i and 2i+1 as children where i is the parent
    bottomUpHeap(H,7);

    for(int i=1; i<=7;i++ )
        printf("%d ",H[i]);
    printf("\n");
}