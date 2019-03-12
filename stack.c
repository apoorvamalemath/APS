#include<stdio.h>
#define SS 5

struct stack{
int item[SS];
int top;
};

typedef struct stack stack;

void push (stack *s, int ele)
{
    if(s->top==SS)
        printf("Stack is full\n");
    else
    {
        s->item[++(s->top)]=ele;
    }

}

void pop(stack *s)
{
    if(s->top==-1)
        printf("Empty\n");
    else
    {
        printf("Popped element is %d\n",s->item[(s->top)]);
        s->top--;
    }
}

int peek(stack *s)
{
    if(s->top==-1)
        printf("Empty\n");
    else
        return s->item[(s->top)];
}

int main()
{
    int done=1;
    stack s;
    s.top=-1;
    while(done)
    {
        int ch;
        int ele;
        printf("---------------------------------------------\n");
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Peek\n");
        scanf("%d",&ch);
        switch(ch){
        case 1: printf("Enter the element\n");
                    scanf("%d",&ele);
                    push(&s,ele);
                    break;
            case 2: pop(&s);
                    break;
            case 3 :printf("Peek element is %d\n ",peek(&s));
                    break;
            default: done=0;

        }



    }
}
