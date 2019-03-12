#include<stdio.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *insert_start(node *start)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    ///typecast to node * as malloc returns null pointer
    if(newnode==NULL)
    {
        printf("Memory Full\n");
        return start;
    }
    printf("Enter the node data:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

        if(start == NULL)
            return newnode;
        else
        {
             newnode->next=start;
             return newnode;
        }


}

node *insert_end(node *start)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    ///typecast to node * as malloc returns null pointer
    if(newnode==NULL)
    {
        printf("Memory Full\n");
        return start;
    }
    printf("Enter the node data:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
        return newnode;
    }
    node *cur;
    cur=start;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }

    cur->next=newnode;
    return start;
}


node *delete_end(node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->next==NULL)
    {
        free(start);
        return NULL;
    }

    node *cur,*prev;
    cur=start;
    prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
    return start;

}

node *delete_start(node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    if(start->next==NULL)
    {
        free(start);
        return NULL;
    }
    node *first;
    first=start->next;
    free(start);
    return first;
}

node *display(node *start)
{
    node *cur=start;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
    return start;
}


int main()
{
    int done=1;
    node *start;
    start=NULL;
   while(done)
    {
        int ch;
    printf("----------------------------------------\n");
    printf("1.Insert at start\n2.Insert at end\n3.Delete from start\n4.Delete from end\n5.Display\n");
    printf("\nEnter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:start=insert_start(start);
                     break;
        case 2:start=insert_end(start);
                     break;
        case 3:start=delete_start(start);
               break;
        case 4:start=delete_end(start);
               break;
        case 5:start=display(start);
                break;
        default: done=0;
    }



    }
}
