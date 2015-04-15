#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int *p1,int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	int a,b;
	int *p1,*p2;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	p1 = &a;
	p2 = &b;
	swap(p1,p2);
	cout << "a=" << a << " ," << "b=" << b << endl;

	return 0;
}
