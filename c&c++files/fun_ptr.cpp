//fun_ptr.cpp --- pointers to functions
#include <iostream>
double betsy(int);
double pam(int);

//second argument is pointer to a type double function that
//takes a type in argument
void estimate(int lines,double (*pf)(int));

int main()
{
	using namespace std;
	int code;

	cout << "how many lines of code do you need:";
	cin >> code;
	cout << "here is betsy's estimate:" << endl;
	estimate(code,betsy);
	cout << "here is pam's estimate:"<< endl;
	estimate(code,pam);
	return 0;
}

double betsy(int lns)
{
	return 0.05*lns;
}

double pam(int lns)
{
	return 0.03*lns + 0.0004*lns *lns;
}

void estimate(int lines,double (*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take:" << endl;
	cout << (*pf)(lines) << " hours()\n";

}
