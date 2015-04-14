#include <iostream>
int main()
{
	using namespace std;
	int yams[3];
	yams[0] = 6;
	yams[1] = 8;
	yams[2] = 7;

	int yamcosts[3] = {20,13,45};
	cout << "total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "the package with" << yams[1] << " yams costs";
	cout << yamcosts[1] << "cents per yam.\n";
	int total  = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "the total yam expense is" << total << " censt" << endl;
	cout << "size of yams array =" << sizeof yams << endl;
	cout << "bytes."<< endl;
	cout << "size of one elem" << sizeof yams[0] << "bites." << endl;
	return 0;
}

