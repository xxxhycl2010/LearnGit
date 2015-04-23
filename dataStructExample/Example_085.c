//----------------------------------------
//this is insert node into the linklist
//author:ycl
//date:2015-04-22
//--------------------------------------------

#include <stdio.h>
#include <malloc.h>

struct student
{
    int num;
    struct student *next;
};

struct student *create(int n)
{
    int i;
    struct student *head, *p1, *p2;
    int a;
    head = NULL;
    printf("input the interger:\n");
    for(i=0;i<n;i++)
    {
        p1 = (struct student*)malloc(sizeof(struct student));
        scanf("%d",&a);
        p1->num = a;
        if(head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    p2->next = NULL;
    return head;
}

void	insertnode(struct student *head,int x,int i)
{
    int j=0;
    struct student *p, *s;
    p = head;
    while(p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1)
    {
        exit(1);
    }
    s=(struct student *)malloc(sizeof(struct student));
    s->num = x;
    s->next = p->next;
    p->next = s;

}

int main()
{
    int n,i;
    int x;
    struct student *q;
    printf("input the counts of nodes you want to create:");
    scanf("%d",&n);
    q = create(n);

    i=2;
    x = 123;
    insertnode(q,x,i);

    printf("the result is:\n");
    while(q)
    {
        printf("%d ",q->num);
        q = q->next;
    }

    return 0;
}
