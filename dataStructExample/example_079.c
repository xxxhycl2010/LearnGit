//--------------------------------
//����˫������
//author:ycl
//date:2015-04-21
//---------------------------------
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char name[20];
	struct node *prior;
	struct node *next;
}stud;			//˫�����Ľṹ����

stud *create(int n)
{
	stud *p, *h, *s;
	int i;
	h = (stud*)malloc(sizeof(stud));
	h->name[0]='\0';
	p->prior = NULL;
	p->next = NULL;
	p=h;
	for(i=0;i<n;i++)
	{
		s = (stud*)malloc(sizeof(stud));
		p->next = s;
		printf("input the %d student's name:",i+1);
		scanf("%s",s->name);
		s->prior = p;
		s->next = NULL;
		p = s;
	}
	p->next = NULL;
	return h;
}

//����
stud *search(stud *h,char *x)
{
	stud *p;
	char *y;
	p = h->next;
	while(p)
	{
		y = p->name;
		if(strcmp(y,x) == 0)
		{
			return p;
		}
		else
		{
			p = p->next;
		}

	}
	printf("can not find data.\n");
}

//ɾ��
void del(stud *p)
{
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
}

int main()
{
	int number;
	char sname[20];
	stud *head, *sp;
	puts("please input the size of the list��");
	scanf("%d",&number);
	head = create(number);
	sp = head->next;
	printf("\nnow the double list is:\n");
	while(sp)
	{
		printf("%s",&*(sp->name));
		sp = sp->next;
	}
	printf("\n please input the name which you want to find:\n");
	scanf("%s",sname);
	sp = search(head,sname);
	printf("the name you wnat to find is:%s\n",*&sp->name);
	del(sp);
	sp = head->next;
	printf("\nnow the double list is :\n");
	while(sp)
	{
		printf("%s",&*(sp->name));
		sp = sp->next;
	}
	printf("\n");
	return 0;
}

