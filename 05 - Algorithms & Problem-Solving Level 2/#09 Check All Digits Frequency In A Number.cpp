// Check All Digits Frequency In A Number
// https://programmingadvices.com/courses/1811531/lectures/41327514/comments/25773256

#include <iostream>

using namespace std;

int CheckFrequency(int number, short digit)
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
	int number;
	cout << "Enter A Number: ";
	cin >> number;

	for (int digit = 0; digit <= 9; digit++)
	{
		int frequency = CheckFrequency(number, digit);
		if (frequency > 0)
			cout << "\nDigit " << digit << " Frequency Is " << frequency << " Time(s).";
	}
}