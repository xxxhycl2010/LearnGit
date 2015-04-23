//---------------------------------------
//this is Joseph ring 
//author:ycl
//date:2015-04-22
//--------------------------------------


#include <stdio.h>
#include <malloc.h>

#define N 9
#define OVERFLOW 0
#define OK 1

int KeyW[N]={4,7,5,9,3,2,6,1,8};

typedef struct LNode
{
	int keyword;
	struct LNode *next;
}LNode, *LinkList;

void Joseph(LinkList p,int m,int x)
{
	LinkList q;
	int i;
	if(x==0)
	  return;
	q = p;
	m%=x;
	if(m==0)
	  m=x;
	for(i=1;i<=m;i++)
	{
		p = q;
		q = p->next;
	}
	p->next = q->next;
	i=q->keyword;
	printf("%d ",q->keyword);
	free(q);
	Joseph(p,i,x-1);
}

int main()
{
	int i,m;
	LinkList Lhead, p, q;
	Lhead = (LinkList)malloc(sizeof(LNode));
	if(!Lhead)
	  return OVERFLOW;
	Lhead->keyword = KeyW[0];
	Lhead->next =NULL;
	p = Lhead;
	for(i=1;i<9;i++)
	{
		if(!(q=(LinkList)malloc(sizeof(LNode))))
		  return OVERFLOW;
		q->keyword = KeyW[i];
		p->next = q;
		p =q;
	}
	p->next = Lhead;
	printf("please input the first record m:\n");
	scanf("%d",&m);
	printf("the output allignment is:\n");
	Joseph(p,m,N);
	return OK;
}
