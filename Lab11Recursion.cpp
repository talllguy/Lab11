/************************************************************
COSC 501
Elliott Plack
13 NOV 2013									Due: 18 NOV 2013
************************************************************/

#include <iostream>

using namespace std;

void loopSimple (int,int); // simple loop function
void loopRecursion (int,int); // loop using recursion
void loopRecursLog (int,int); // loop using recursion and log n
void loopExponential (int,int); // loop using o(2^n) which may take a long time to run.

int main ()
{
	int x = 0, n = 0;
	int choice = 0; // choice for case

	//input
	cout << "Enter a value for x and n to process big O notation for. \n";
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter n: ";
	cin >> n;

	// switch for algorithm choice
	cout << "Type the number corresponding to the function you wish to perform below:\n"
		 << "1. A function that uses a loop to calculate x<sup>n</sup> in O(n)\n"
		 << "2. A function that recursively calculates x<sup>n</sup> in O(n)\n"
		 << "3. A function that recursively calculates x<sup>n</sup> in O(log n)\n"
		 << "4. A function that has O(2<sup>n</sup>) time complexity.\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		loopSimple(x, n);
		break;
	case 2:
		loopRecursion(x, n);
		break;
	case 3:
		loopRecursLog(x, n);
		break;
	case 4:
		loopExponential(x, n);
		break;
	default:
		break;
	}

	return 0; // end
}

void loopSimple (int x,int n)
{
	x = pow(x,n);
	cout << "x^n = " << x;
}

void loopRecursion (int x,int n)
{

}

void loopRecursLog (int x,int n)
{

}

void loopExponential (int x,int n)
{

}