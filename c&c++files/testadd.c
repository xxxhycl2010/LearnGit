#include <stdio.h>


int main()
{
	int a[4]={1,2,3,4};
	int *p;
	p = a;
	int i;
	for(i=0;i<4;i++)
	{
//		printf("%d ",*p++);
		printf("%d ",*++p);
	}
	return 0;
}

