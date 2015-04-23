//-------------------------------
//function: this is merge two linklist
//author: ycl
//date:2015-04-23
//------------------------------------



#include <stdio.h>
#include <malloc.h>

typedef struct student
{
    int num;
    struct student *next;

}LNode, *LinkList;


LinkList create(void)
{
    LinkList head;
    LNode *p1, *p2;
    head = NULL;
    int a;
    scanf("%d",&a);
    while(a != 0)
    {
        p1 =(LinkList)malloc(sizeof(LNode));
        p1->num = a;
        if(head == NULL)
        {
            head = p1;

        }
        else
            p2->next = p1;
        p2 = p1;
        printf("a=");
        scanf("%d",&a);

    }
    p2->next = NULL;
    return head;

}

LinkList MergeList(LinkList la,LinkList lb)
{
    LNode *temp;
    if(la == NULL)
        return lb;
    else
    {
        if(lb != NULL)
        {
            for(temp = la;temp->next != NULL;temp = temp->next);
            temp->next = lb;

        }
    }
    return la;
}




int main(void)
{

    LinkList L1,L2;
    printf("please input two list:\n");
    printf("please first list:\n");
    L1 = create();
    printf("please second list:\n");
    L2 = create();
    MergeList(L1,L2);
    printf("the result merge list is :\n");
    while(L1)
    {

        printf("%d ",L1->num);
        L1 = L1->next;
    }



    return 0;
}

