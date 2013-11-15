/************************************************************
COSC 501
Elliott Plack
13 NOV 2013									Due: 18 NOV 2013
************************************************************/

#include <iostream>
#include <time.h>

using namespace std;

double loopSimple (double,int); // simple loop function
double loopRecursion (double,int); // loop using recursion
double loopRecursLog (double,int); // loop using recursion and log n
double loopExponential (int); // loop using o(2^n) which may take a long time to run.

int main ()
{
	double x = 0, simpleResult = 0, recursiveResult = 0, recLogNResult = 0, exponentialResult = 0;
	int n = 0, choice = 0;
	double duration = 0;

	cout << "To process big O notation for x and n: press 1\n"
		<< "To illustrate time complexity of 2^n  : press 2\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Enter a value for x and n to process big O notation for. \n";
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter n: ";
		cin >> n;

		simpleResult = loopSimple(x, n);
		recursiveResult = loopRecursion(x, n);
		recLogNResult = loopRecursLog(x, n);

		cout << "This program :\n"
			<< "1. Using a loop to calculate x^n yields ........... " << simpleResult << endl
			<< "2. Recursively calculating x^n yields ............. " << recursiveResult << endl
			<< "3. Recursively calculating x^n using logn yields .. " << recLogNResult << endl;
		break;
	case 2:
		cout << "Enter a value for n to test time complexity for 2^n: ";
		cin >> n;
		
		//start clock
		clock_t start;
		start = clock();
		// run function
		exponentialResult = loopExponential(n);
		// end clock
		duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
		cout << "4. Calculating (2^n) in big O notation yields ..... " << exponentialResult << endl
			<< "This took " << duration << " seconds.\n";
		break;
	default:
		break;
	}

	return 0; // end
}

double loopSimple (double x,int n) // simple exponential loop
{
	double result = 1;
	for (int i = 0; i < n; i++)
	{
		result = x * result;
	}
	return result;
}

double loopRecursion (double x,int n) // loop using recursion
{
	if ( n == 0 )
		return 1;
	else
		return x * loopRecursion (x, n - 1); // call of function in function is recursive

}

double loopRecursLog (double x,int n) // more efficient calculation because the possibility is cut in half each time
{
	if ( n == 0 ) { return 1; }
	else if ( n == 1 ) return x;
	else if (n % 2 == 0)
		return loopRecursLog (x*x, n/2);
	else 
		return loopRecursLog (x*x, n/2) * x;
}

double loopExponential (int n) // long long loop to calculate exponential, can take a long time.
{
	double power = 1, result = 0;
	double j = 1, k = 1;
	for(j=1; j <= n; j++)
	{
		power = power * 2;
		for(k=1; k<= power; k++)
			//cout << k << endl;
			result = k;
	}
	return result;
}