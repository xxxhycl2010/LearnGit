//-----------------------------------------
//this is create order linklist and insert the element
//author:ycl
//date:2015-04-22
//---------------------------------------------

#include <stdio.h>
#include <malloc.h>

#define Listsize 100

struct sqlist
{
	int data[Listsize];
	int length;
};

void InsertList(struct sqlist *_l,int t,int i)
{
	int j;
	if(i<0 || i>_l->length)
	{
		printf("position error:\n");
		exit(1);
	}
	if(_l->length >= Listsize)
	{
		printf("overflow");
		exit(1);
	}
	//insert elem
	for(j=_l->length-1;j>=i;j--)
	{
		_l->data[j+1] = _l->data[j];

	}
	_l->data[i] = t;
	_l->length++;
}

int main()
{
	struct sqlist *sq;
	int i,n,t;
	sq =(struct sqlist*)malloc(sizeof(struct sqlist));
	sq->length = 0;
	printf("please input the size of the list:");
	scanf("%d",&n);
	printf("please input the element of the list:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		InsertList(sq,t,i);
	}
	printf("now the list is:\n");
	for(i=0;i<sq->length;i++)
	{
		printf("%d ",sq->data[i]);
	}
	return 0;
}


