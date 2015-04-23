//------------------------------------
//function: remove node for the linklist
//author:ycl
//date:20156-04-23
//------------------------------------

#include <stdio.h>
#include <malloc.h>

typedef struct student
{
	int num;
	struct student *next;
}LNode, *Linklist;

struct student *create(int n)
{
	int i;
	struct student *head, *p1, *p2;
	int a;
	head = NULL;
	printf("the record is:");
	for(i=n-1;i>=0;i--)
	{
		p1= (struct student*)malloc(sizeof(struct student));
		printf("num=");
		scanf("%d",&a);
		p1->num = a;
		if(head==NULL)
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

void delnode(Linklist &head,int i)
{
	int j=0;
	struct student *p,*r;
	p = head;
	while(p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(p->next || j > i-1)
	  exit(1);
	r = p->next;
	p->next = r->next;
	free(r);
}

int main()
{
	int n,i;
	int x;
	struct student *q;
	printf("input the count of the nodes you want to create:");
	scanf("%d",&n);
	q = create(n);
	
	i = 2;
	delnode(q,i);
	printf("the third record deleted , the result is :\n");
	
	while(q)
	{
		printf("%d ",q->num);
		q = q->next;
	}

	
	return 0;
}

