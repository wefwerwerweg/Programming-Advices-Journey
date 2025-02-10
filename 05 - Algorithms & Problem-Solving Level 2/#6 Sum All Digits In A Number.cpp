// Sum All Digits In A Number
// https://programmingadvices.com/courses/1811531/lectures/41306747/comments/25772868

#include <iostream>

using namespace std;

int SumDigits(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n;
	cout << "Sum All Digits In: ";
	cin >> n;
	cout << "Sum Of Digits = " << SumDigits(n);
}