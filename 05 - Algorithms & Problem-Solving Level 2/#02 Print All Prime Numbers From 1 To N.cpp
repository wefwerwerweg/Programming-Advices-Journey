// Print All Prime Numbers From 1 To N
// https://programmingadvices.com/courses/1811531/lectures/41203608/comments/25767535

#include <iostream>

using namespace std;

bool CheckPrime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;

	for (int i = 3; i <= sqrt(x); i += 2)
		if (x % i == 0) return false;

	return true;
}

int main()
{
	int n;
	cout << "Print All Prime Numbers From 1 To: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
		if (CheckPrime(i)) cout << i << endl;
}