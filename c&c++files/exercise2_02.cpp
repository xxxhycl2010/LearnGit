#include <iostream>

using namespace std;
void swap(int *p1,int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void exchange(int *pt1,int *pt2,int *pt3)
{
	// from large to small
	if(*pt1 < *pt2)
	{
		swap(pt1,pt2);
	}
	if(*pt1 < *pt3)
		swap(pt1,pt3);
	if(*pt2 < *pt3)
		swap(pt2,pt3);
}




int main()
{
	int a,b,c, *p1,*p2,*p3;
	cout << "please enter three num:";
	cin >> a >> b >> c;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	exchange(p1,p2,p3);
	cout << "a=" << a << ",b="<< b << ",c="<< c << endl;
	return 0;
}
