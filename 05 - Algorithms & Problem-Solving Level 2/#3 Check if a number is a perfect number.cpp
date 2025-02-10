// Check if a number is a perfect number
// https://programmingadvices.com/courses/1811531/lectures/41205480/comments/25772286

#include <iostream>

using namespace std;

string CheckPerfectNumber(int n)
{
	int sum = 0;

	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0) sum += i;

	if (sum == n) return " is perfect.\n";
	else return " is not perfect.\n";
}

int main()
{
	int n;
	cout << "Check Perfect Number: ";
	cin >> n;
	cout << n << CheckPerfectNumber(n);
}