#include<stdio.h>
int arr[100];
int n;

void Union(int a,int b)
{
    int i;
    arr[a]=arr[b];
    for(i=0;i<n;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
}

void Find(int a, int b)
{
    if(arr[a]==arr[b])
        printf("Subset\n");
    else
        printf("Disjoint Set\n");
}

int main()
{
    int i;
    int done=1;
    int ch;
    int a,b;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=i;
    }
    while(done)
    {
        printf(" 1.Union \n 2.Find \n 3.Exit \n Enter your choice:\n");
        scanf("%d",&ch);
        //printf("--- %d",ch);
        if(ch==1)
        {
            printf("Enter the numbers:\n");
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        else if(ch==2)
        {
            printf("Enter the numbers:\n");
            scanf("%d%d",&a,&b);
            Find(a,b);
        }
        else
            done=0;
    }

    return 0;
}
