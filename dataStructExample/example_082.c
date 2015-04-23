//----------------------------------------------
//this is double linklist and then to reverse to printf
//author:ycl
//date:2015-04-22
//--------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#define N 10

typedef struct node
{
	char name[20];
	struct node *prior, *next;
}stud;

//create double linklist
stud *create(int n)
{
	stud *p, *h, *s;
	int i;
	h = (stud*)malloc(sizeof(stud));
	// init head node
	h->name[0]='\0';
	h->prior = NULL;
	h->next = NULL;
	p = h;
	printf("input the records:\n");
	for(i=0;i<n;i++)
	{
		s=(stud*)malloc(sizeof(stud));
		p->next = s;
		scanf("%s",s->name);
		s->prior = p;
		s->next = NULL;
		p =s;
	}
	p->next = NULL;
	return h;

}

stud *gettp(stud *head)
{
	stud *p, *r;
	while(p->next != NULL)
	{
		p= p->next;
	}
	return p;			// return rear node pointer
}

int main()
{
	int n,i;
	int x;
	stud *q;
	printf("input the count of the nodes you want to create:");
	scanf("%d",&n);
	q = create(n);
	q = gettp(q);
	printf("the result is:");
	while(q)
	{
		printf("  %s",&*(q->name));
		q = q->prior;
	}

	return 0;
}



