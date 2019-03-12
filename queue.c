#include<stdio.h>
#define SS 5

struct queue{
    int item[SS];
    int rear;
    int front;
};

typedef struct queue queue;

void enqueue(queue *q, int ele)
{
    if(q->rear==SS-1)
        printf("Queue is full\n");
    else
    {
        q->item[++(q->rear)]=ele;
    }
}

void dequeue(queue *q)
{
    if(q->front>q->rear)
        printf("Queue is empty \n");
    else
    {
        printf("The dequeued element is %d\n",  q->item[(q->front)++]);
    }
}

void display(queue *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
        printf("%d ",q->item[i]);
    printf("\n");
}

int main()
{
    int done=1;
    queue q;
    q.front=0;
    q.rear=-1;
    while(done)
    {
        int ch;
        int ele;
        printf("---------------------------------------------\n");
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d",&ch);
        switch(ch){
        case 1: printf("Enter the element\n");
                    scanf("%d",&ele);
                    enqueue(&q,ele);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3 :display(&q);
                    break;
            default: done=0;

        }



    }
}
