/********************************************************************
COSC 501
Elliott Plack
13 NOV 2013        							Due: 18 NOV 2013
Problem:
    Develop three functions that must satisfy the Big-O
	requirements as shown below

    1. Develop a function that uses a loop to calculate x^n in O(n)
    2. Develop a function that recursively calculates x^n in O(n)
    3. Develop a function that recursively calculates x^n in O(log n)
    4. Develop a function that has O(2^n) time complexity.
Algorithm:
    Write various loops to satisfy requirements. For the final problem
	implement a timer to test.
**********************************************************************/

#include <iostream>
#include <time.h>

using namespace std;

double loopSimple (double,int); // simple loop function
double loopRecursion (double,int); // loop using recursion
double loopRecursLog (double,int); // loop using recursion and log n
void loopExponential (int); // loop using o(2^n) which may take a long time to run.

int main ()
{
	double x = 0, simpleResult = 0, recursiveResult = 0, recLogNResult = 0; // variables
	int n = 0, choice = 0;
	double durationSimple = 0, durationRecursive = 0, durationLogN = 0, durationExpon = 0; // for the clock

	cout << "To process big O notation for x and n: press 1\n"
		<< "To illustrate time complexity of 2^n  : press 2\n";
	cin >> choice;

	switch (choice)
	{
	case 1: // big O notation prob. input x & n and all three things will calculate
		cout << "Enter a value for x and n to process big O notation for. \n";
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter n: ";
		cin >> n;

		// first function

		//start clock
		clock_t startSimple;
		startSimple = clock();
		// run function
		simpleResult = loopSimple(x, n); // go
		// end clock
		durationSimple = (clock() - startSimple ) / (double) CLOCKS_PER_SEC;

		// second function

		//start clock
		clock_t startRecurs;
		startRecurs = clock();
		// run function
		recursiveResult = loopRecursion(x, n); // go
		// end clock
		durationRecursive = (clock() - startRecurs ) / (double) CLOCKS_PER_SEC;

		// third function

		//start clock
		clock_t startLogN;
		startLogN = clock();
		// run function
		recLogNResult = loopRecursLog(x, n); // go
		// end clock
		durationLogN = (clock() - startLogN ) / (double) CLOCKS_PER_SEC;


		cout // all on next line for visualization
			<< "1. Using a loop to calculate x^n yields ........... " << simpleResult << ", which took " <<
			durationSimple << " seconds.\n"
			<< "2. Recursively calculating x^n yields ............. " << recursiveResult << ", which took " <<
			durationRecursive << " seconds.\n"
			<< "3. Recursively calculating x^n using logn yields .. " << recLogNResult << ", which took " <<
			durationLogN << " seconds.\n";
		break;
	case 2: // time complexity, may take a while
		cout << "Enter a value for n to test time complexity for 2^n: ";
		cin >> n;
		
		//start clock
		clock_t startExp;
		startExp = clock();
		// run function
		loopExponential(n);
		// end clock
		durationExpon = (clock() - startExp ) / (double) CLOCKS_PER_SEC;
		cout << "This took " << durationExpon << " seconds.\n";
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

void loopExponential (int n) // long long loop to calculate exponential, can take a long time.
{
	double power = 1, result = 0;
	double j = 1, k = 1;
	for(j=1; j <= n; j++)
	{
		power = power * 2;
		for(k=1; k<= power; k++)
			cout << k << endl;
	}
}