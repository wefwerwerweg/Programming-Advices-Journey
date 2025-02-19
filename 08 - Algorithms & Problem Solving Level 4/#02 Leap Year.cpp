// #2 Leap Year
// https://programmingadvices.com/courses/1890122/lectures/42994247/comments/25862413

#include <iostream>

using namespace std;

bool IsLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else return false;
}

int main()
{
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (IsLeapYear(year))
		cout << "Yes, it is a leap year.\n";
	else cout << "No, it is not a leap year.\n";
	return 0;
}
