// Print All Perfect Numbers From 1 To N
// https://programmingadvices.com/courses/1811531/lectures/41206435/comments/25772387

#include <iostream>

using namespace std;

bool CheckPerfectNumber(int n)
{
	int sum = 0;

	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0) sum += i;

	return sum == n;
}

int main()
{
	int n;
	cout << "Print All Perfect Numbers From 1 To: ";
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		if (CheckPerfectNumber(i)) cout << i << endl;
}