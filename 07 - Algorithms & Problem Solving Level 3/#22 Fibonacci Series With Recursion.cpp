// #22 Fibonacci Series With Recursion
// https://programmingadvices.com/courses/1869980/lectures/42568088/comments/25839686

#include <iostream>

using namespace std;

void PrintFibonacciWithRecursion(short num, int prev = 0, int prev1 = 0)
{
	if (!prev && !prev1)
	{
		cout << ++prev;
	}
	else
	{
		int x = prev + prev1;
		prev1 = prev;
		prev = x;
		cout << "    " << x;
	}

	if (num > 1) PrintFibonacciWithRecursion(num - 1, prev, prev1);
}

int main()
{
	short num;
	cout << "Fibonacci Series Length: ";
	cin >> num;
	cout << endl;
	PrintFibonacciWithRecursion(num);
	cout << endl;
	return 0;
}
