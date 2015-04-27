//--------------------------------------------
//function: this is head insert node to create linklist
//author:ycl
//date:2015-04-27
//---------------------------------------------------------



#include <stdio.h>
#include <malloc.h>


typedef struct student
{
    char num;
    struct student *next;
}LNode, *LinkList;


LinkList create()
{
   LinkList head;
   LNode *p1;
   char a;
   head = NULL;
   printf("please input the linklist records\n");
   a = getchar();
   while( a!='\n')
   {
       p1 = (LinkList)malloc(sizeof(LNode));
       p1->num = a;
       p1->next = head;
       head = p1;
       a = getchar();


   }
   return head;

}



int main()
{
   LinkList L1;
   L1 = create();
   printf("the linklist is:\n");
   while(L1)
   {
       printf("%c ",L1->num);
        L1 = L1->next;
   }



    return 0;

}
