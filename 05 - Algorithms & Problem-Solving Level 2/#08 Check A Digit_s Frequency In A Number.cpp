// Check A Digit's Frequency In A Number
// https://programmingadvices.com/courses/1811531/lectures/41327479/comments/25773060

#include <iostream>

using namespace std;

int CheckFrequency(int number, int digit)
{
	int frequency = 0;
	while (number != 0)
	{
		if (number % 10 == digit) frequency++;
		number /= 10;
	}
	return frequency;
}

int main()
{
	int number, digit;
	cout << "Enter A Number: ";
	cin >> number;
	cout << "Enter A Digit : ";
	cin >> digit;

	cout << "\nDigit " << digit << " Frequency Is " << CheckFrequency(number, digit) << " Time(s).\n";
}