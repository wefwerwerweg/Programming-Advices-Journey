// #3 Leap Year One Line Of Code
// https://programmingadvices.com/courses/1890122/lectures/42994250/comments/25862436

#include <iostream>

using namespace std;

bool IsLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
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
