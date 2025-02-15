// #21 Fibonacci Series
// https://programmingadvices.com/courses/1869980/lectures/42568088/comments/25839686

#include <iostream>

using namespace std;

void PrintFibonacciSeries(short num)
{
	int prev = 1, prev1 = 1;
	cout << "1  1  ";
	for (short i = 3; i <= num; i++)
	{
		int x = prev + prev1;
		cout << x << "  ";
		prev1 = prev;
		prev = x;
	}
}

int main()
{
	short num;
	cout << "Fibonacci Series Length: ";
	cin >> num;
	PrintFibonacciSeries(num);
	return 0;
}
