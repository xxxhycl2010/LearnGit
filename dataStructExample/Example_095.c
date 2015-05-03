//Example_095.c -- this is linklist queue


#ifndef EXAMPLE_095_H
#define EXAMPLE_095_H

#endif // EXAMPLE_095_H

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
    ElemType  data;
    struct node *next;
}quenode;

struct quefr
{
    quenode *front, *rear;
};

void create(struct quefr *q)
{
    quenode *h;
    h = (quenode*)malloc(sizeof(quenode));
    h->next = NULL;
    q->front = h;
    q->rear = h;
}

//elem  into queue
void enqueue(struct quefr *q,ElemType x)
{
    quenode *s;
    s = (quenode*)malloc(sizeof(quenode));
    s->data = x;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;


}

//elem out queue
ElemType dequeue(struct quefr *q)
{
    quenode *p;
    ElemType x;
    p=(quenode*)malloc(sizeof(quenode));

    if(q->front == q->rear)
    {
        printf("queue is null\n");
        x =0;
    }
    else
    {
        p = q->front->next;
        q->front->next = p->next;
        if(p->next == NULL)
        {
            q->rear = q->front;
        }
        x = p->data;
        free(p);
    }

    return x;
}

//show all elem in queue
void display(struct quefr dq)
{
    quenode *p;
    p = (quenode*)malloc(sizeof(quenode));
    p = dq.front->next;
    while(p!= NULL)
    {
        printf("data = %d\n",p->data);
        p = p->next;
    }
    printf("end \n");
}


void TestExmaple_095(struct quefr *que)
{
    int n,i,x,sel;
    do
    {
        printf("\n");
        printf("        1   create queue\n");
        printf("        2   into the queue\n");
        printf("        3   delete from queue\n ");
        printf("        4   display\n");
        printf("        5   exit\n");
        printf("-------------------------------\n");
        printf("please choose(1,2,3,4,5)");
        scanf("%d",&sel);
        switch (sel) {

        case 1:
            que = (struct quefr*)malloc(sizeof(struct quefr));
            create(que);
            printf("please input the number of elem  you want to create:");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                scanf("%d",&x);
                enqueue(que,x);
            }
            break;
        case 2:
            printf("please input the elem:");
            scanf("%d",&x);
            enqueue(que,x);
            break;
        case 3:
            printf("x=%d\n",dequeue(que));
            break;
        case 4:
            display(*que);
            break;
        case 5:
            exit(0);

            break;
        default:
            break;
        }
    }while(sel <=4);
}
