#include <iostream>

using namespace std;

int main()
{
	int age1 = 14;
	int age2 = 27;
	const int *p1;
	p1 = &age1;
	cout << "p1 address=" << p1 << endl;
	cout << "*p1" << *p1 << endl;
	p1 += 1;
	cout << "*p1 de value add 1:"<< endl;
	cout << "new p1 address ="<< p1 << endl;
       cout << "new *p1=" << *p1 << endl;	
//	cout << "*p1 +1 =" << *p1 << endl;
	
	p1 = &age2;
	cout << "change p1 address after:"<< endl;
	cout << "new p1 address" << p1 << endl;
	cout << "new *p1" << *p1 << endl;
	int age3 = 34;
	int *test = &age3;
	cout << "*test address=" << test << endl;
	cout << "*test=" << *test << endl;
	*test += 1;
	cout << "test address add 1"<< endl;
	cout << "new test adderss =" << test << endl;
	cout << " new *test= "<< *test << endl;
	



	int *  const p2 = &age2;



	cout << "*p2 address= "<< p2 << endl;
	cout << "*p2=" << *p2 << endl;
	*p2 += 1;
	cout << "p2 value add 1" << endl;
	cout << "p2 adddress" << p2 << endl;
	cout << "*p2 =" << *p2 << endl;
	
//	p2 += 1;
//	cout << "p2 address add 1:"<< endl;
//	cout << "new  p2 address = " << p2 << endl;
//	cout << "new p2 value" <<*p2 << endl;
	int a = 34;

	*p2 = a;
	cout << "new p2 address=" << p2 << endl;
	cout << "new *p2 value =" << *p2 << endl;
	return 0;
//	*p1 += 1;
	
}
