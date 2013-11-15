/************************************************************
COSC 501
Elliott Plack
13 NOV 2013									Due: 18 NOV 2013
************************************************************/

#include <iostream>

using namespace std;

double loopSimple (double,int); // simple loop function
double loopRecursion (double,int); // loop using recursion
double loopRecursLog (double,int); // loop using recursion and log n
double loopExponential (int); // loop using o(2^n) which may take a double time to run.

int main ()
{
	double x = 0, result1 = 0, result2 = 0, result3 = 0, result4 = 0;
	int choice = 0, n = 0; // choice for case

	//input
	cout << "Enter a value for x and n to process big O notation for. \n";
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter n: ";
	cin >> n;

	// switch for algorithm choice
	cout << "Type the number corresponding to the function you wish to perform below:\n"
		 << "1. A function that uses a loop to calculate x^n in O(n)\n"
		 << "2. A function that recursively calculates x^n in O(n)\n"
		 << "3. A function that recursively calculates x^n in O(log n)\n"
		 << "4. A function that has O(2^n) time complexity.\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		result1 = loopSimple(x, n);
		cout << result1;
		break;
	case 2:
		result2 = loopRecursion(x, n);
		cout << result2;
		break;
	case 3:
		result3 = loopRecursLog(x, n);
		cout << result3;
		break;
	case 4:
		result4 = loopExponential(n);
		cout << result4;
		break;
	default:
		break;
	}

	return 0; // end
}

double loopSimple (double x,int n)
{
	double result = 1;
	for (int i = 0; i < n; i++)
	{
		result = x * result;
	}
	return result;
}

double loopRecursion (double x,int n)
{
	if ( n == 0 )
		return 1;
	else
		return x * loopRecursion (x, n - 1);

}

double loopRecursLog (double x,int n)
{
	if ( n == 0 ) { return 1; }
	else if ( n == 1 ) return x;
	else if (n % 2 == 0)
		return loopRecursLog (x*x, n/2);
	else 
		return loopRecursLog (x*x, n/2) * x;
}

double loopExponential (int n)
{
	double power =1;
	for(int j=1; j <= n; j++)
	{
		power = power * 2;
		for(int k=1; k<= power; k++)
			cout << k << endl;
	}
	return 0;
}