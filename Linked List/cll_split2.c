 #include<stdio.h>

struct NODE
{
    int info;
    struct NODE *next;
};

typedef struct NODE node;
//node *head2=NULL;
//node *head3=NULL;
node* getnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->next=NULL;
    return p;
}
static int count=0;

void printList(node **head)
{
  node *cur;
  cur=*head;
  if(*head==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
cur=*head;

  while (cur->next!= *head)
  {
     printf(" %d ", cur->info);
     cur = cur->next;

  }
  printf(" %d ",cur->info);
  printf(" exected");
    }
}

void InsertNodeFront(node **head)
{
    int num;
    node *newnode;
    node *current;
    newnode=(node*)malloc(sizeof(struct NODE));
    printf("Enter data:");
    scanf("%d",&num);
    newnode->info=num;
    newnode->next=NULL;
    count++;
    if(*head==NULL)        //If list is empty
    {
        *head=newnode;
        newnode->next=*head;
    }
    else
    {
        current=*head;
       while(current->next!=*head)
        current=current->next;
        current->next=newnode;
        newnode->next=*head;
        //*head=newnode;

        printf("%d inserted",newnode->info);
    }

}

void insertlist(node **head,int *data)
{
    node *newnode,*current;
    newnode=(node*)malloc(sizeof(struct NODE));
    newnode->info=*data;
    newnode->next=NULL;
    if(*head==NULL)        //If list is empty
    {
        *head=newnode;
        newnode->next=*head;
    }
    else
    {
        current=*head;
       while(current->next!=*head)
        current=current->next;
        current->next=newnode;
        newnode->next=*head;
        //printf("%d inserted",newnode->info);
    }


}

void split(node **head,node **head2,node **head3)
{
  int m=count/2;
  printf("coun %d m %d\n",count,m);
  int n=0;
  node *cur,*l1,*l2;
  cur=*head;
  //*head2=NULL;
 while(n<m)
  {
      insertlist(head2,&cur->info);
      cur=cur->next;
      n++;
      printf("in %d\n",n);

  }

  while(n<count)
  {
      insertlist(head3,&cur->info);
      cur=cur->next;
      //l2=l2->next;
      n++;
  }
  //l2=head3;*/


}

main()
{
    node *n;
    node *head=NULL;
    node *head2=NULL;
    node *head3=NULL;
    int done=0;
    int ch;
    while(done==0)
    {
        printf("Enter the choice: \n1.Insert\n2.split\n3.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1: InsertNodeFront(&head);
                   break;
           case 2:split(&head,&head2,&head3);
                   printList(&head2);
                  printf("\n");
                  printList(&head3);
                  break;
           case 3:printList(&head);
                  break;
           case 4: done=1;
        }
    }

}
