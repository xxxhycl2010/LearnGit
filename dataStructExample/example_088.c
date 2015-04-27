//--------------------------------------------
//function: this is single linklist ,and then reverse all the nodes
//author:ycl
//date:2015-04-27
//---------------------------------------------------------



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
    printf("the record is :\n");
    for(i=0;i<n;i++)
    {
        p1 = (struct student*)malloc(sizeof(struct student));
        printf("a=");
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
        printf("\n");

    }
    p2->next = NULL;
    return head;

}

//realize reverse
struct student *reverse(struct student *head)
{
    struct student *p, *r;
    if(head->next && head->next->next)
    {
        p = head;
        r = p->next;
        p->next = NULL;
        while(r)
        {
            p = r;
            r = r->next;
            p->next = head;
            head = p;
        }

    }
    return head;
}


int main()
{
    int n;

    struct student *q;
    printf("input the count of the nodes you want to create:");
    scanf("%d",&n);
    printf("n=%d\n",n);
    q = create(n);
    q = reverse(q);
    printf("the reverse linklist is :\n");
    while(q)
    {
        printf("%d  ",q->num);
        q = q->next;
    }

    return 0;

}
