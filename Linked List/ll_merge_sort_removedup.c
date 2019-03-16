#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *insertEND(node *head)
{
    int num;
    node *cur,*newnode;
    cur=head;
    printf("Enter the number to be inserted:\n");
    scanf("%d",&num);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newnode;
    }
    return head;
}

node *display(node *head)
{
    node *cur;
    cur=head;
    if(cur==NULL)
    {
        printf("Empty\n");
    }
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
    return head;
}

node *merge(node *head1, node *head2)
{
    node *cur1,*cur2;
    cur1=head1;
    cur2=head2;
    while(cur1->next!=NULL)
    {
        cur1=cur1->next;
    }
    while(cur2!=NULL)
    {
        cur1->next=cur2;
        cur2=cur2->next;
        cur1=cur1->next;
    }
    return head1;
}
/*  NOT WORKING
node *duplicate(node *head)
{
    node *cur,*temp,*temp2,*prev;
    cur=head;
    temp=head;
    int n1=0,n2=0,pos;
    while(cur->next!=NULL)
    {
        temp=cur->next;
        prev=cur;
        while(temp!=NULL)
        {
            if(cur->data==temp->data)
            {

                printf("EQUAL");
                temp2=temp;
                prev=temp->next;
                //temp->next=temp->next->next;
                printf("FREE 2 %d",temp->data);
                free(temp2);
                //deletePOS(&head,pos);
                printf("DEL at %d\n",n2);
               break;
            }
            else
                temp=temp->next;

        }
        cur=cur->next;
    }
    return head;
}

void deletePOS(node **head,int pos)
{

     node *cur,*temp,*temp2;
    int count=1,i;
    cur=*head;
    temp=*head;
    //printf("Enter the position:\n");
    //scanf("%d",&pos);
    if(pos==1)
    {
      temp2=*head;
      *head=cur->next;
      printf("FREE %d",temp2->data);
      free(temp2);
      //1return;
    }
    else
    {
        cur=*head;
        for(i=1;i<pos;i++)
        {
            temp=cur;
            cur=cur->next;
        }
        temp->next=cur->next;
         printf("FREE 2 %d",cur->data);
        free(cur);
        //return;
    }
}*/
//working
void dup_delete(struct node **head)

{
    struct node *p, *q, *prev, *temp;
    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}

node *sort(node *head)
{
    node *cur1,*cur2;
    cur1=head;
    int temp;
   // cur2=cur1->next;
    while(cur1!=NULL)
    {
        cur2=head;
        while(cur2!=NULL)
        {


        if(cur2->data>cur1->data)
        {
            temp=cur1->data;
            cur1->data=cur2->data;
            cur2->data=temp;
        }
        cur2=cur2->next;
        }
        cur1=cur1->next;
        //cur2=cur2->next;
    }
    return head;
}

void removeDuplicates(node **head)
{
    /* Pointer to traverse the linked list */
    node* current = *head;

    /* Pointer to store the next pointer of a node to be deleted*/
    node* next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
       return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
       /* Compare current node with next node */
       if (current->data == current->next->data)
       {
           /* The sequence of steps is important*/
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next;
       }
       //return head;
    }
}
main()
{
    node *head1,*head2;
    //node *temp;
    head1=NULL;
    head2=NULL;
    int ch,done=1;
    while(done)
    {
    printf("1.Insert 1\n2.Insert 2\n3.Display 1\n4.display 2\n5.merge\n6.Remove Duplicate\n7.Sort\n");
    printf("Enter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:head1=insertEND(head1);
                     break;
        case 2:head2=insertEND(head2);
                     break;
        case 3:head1=display(head1);
               break;
        case 4:head2=display(head2);
               break;
        case 5:head1=merge(head1,head2);
               head1=display(head1);
                break;
        case 6://dup_delete(&head1);
               removeDuplicates(&head1);
               head1=display(head1);
               break;
        case 7:head1=sort(head1);
                head1=display(head1);
               break;
        default: done=0;
    }



    }
}
