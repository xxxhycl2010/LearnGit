// create simple single list


#include <stdio.h>
#include <malloc.h>

struct LNode
{
	int data;
	struct LNode *next;
};

struct LNode *create(int n)
{
	int i;
	struct LNode *head, *p1, *p2;
	int a;
	head = NULL;
	printf("input the integer:\n");
	for(i=n;i>=0;i--)
	{
		p1 = (struct LNode*)malloc(sizeof(struct LNode));
		scanf("%d",&a);
		p1->data =a;
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

int main()
{
	int n;
	struct LNode *q;
	printf("input the count of the nodes you want to creat:");
	scanf("%d",&n);
	q = create(n);
	printf("the result is:\n");
	while(q)
	{
		printf("%d \t",q->data);
		q = q->next;
	}


	return 0;
}

