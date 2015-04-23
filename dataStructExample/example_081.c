// ---------------------------------------------------------
// this is create a two-way linked list, then nodes inverse
// author:ycl
// date:2015-04-22
// -------------------------------------------------------------
#include <stdio.h>
#include <malloc.h>

#define N 10

typedef struct node
{
	char name[20];
	struct node *prior,*next;
}stud;

//create a two way linked list
stud *create(int n)
{
	stud *p, *h, *s;
	int i;
	h = (stud*)malloc(sizeof(stud));
	//init head node
	h->name[0]='\0';
	h->prior = NULL;
	h->next = NULL;
	p = h;					// p point to the head node
	printf("input the records:\n");
	for(i=0;i<n;i++)
	{
		s=(stud*)malloc(sizeof(stud));
		p->next = s;

		scanf("%s",s->name);
		s->prior = p;
		s->next = NULL;
		p = s;
	}
	p->next = NULL;
	return h;

}

stud *reverse(stud *head)
{
	stud *p, *r, *h;
	h = head->next;
	// realize reverse
	if(h && h->next)
	{
		p = h;
		r = p->next;
		p->next = NULL;
		while(r)
		{
			p = r;
			r = r->next;
			p->next = h;
			h->prior = p;
			h = p;
		}
		head->next = h;
		h->prior = head;
		return head;
	}
}




int main()
{
	int n,i;
	int x;
	stud *q;
	printf("input the count of the nodes you want to create:");
	scanf("%d",&n);
	q = create(n);
	q = reverse(q);
	printf("the result linklist :\n");
	while(q)
	{
		printf("%s  ",&*(q->name));
		q = q->next;
	}

	return 0;
}
