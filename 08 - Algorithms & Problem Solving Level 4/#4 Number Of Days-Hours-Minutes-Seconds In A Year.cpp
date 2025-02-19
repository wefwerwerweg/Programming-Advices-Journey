// #4 Number Of Days-Hours-Minutes-Seconds In A Year
// https://programmingadvices.com/courses/1890122/lectures/42994251/comments/25862520

#include <iostream>
#include <string>

using namespace std;

bool IsLeapYear(short year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void PrintYearFormated(short year)
{
	short days = IsLeapYear(year) ? 366 : 365;
	short hours = days * 24;
	int minutes = hours * 60;
	int seconds = minutes * 60;
	cout << "\nNumber of Days    in Year [" << year << "] is " << days;
	cout << "\nNumber of Hours   in Year [" << year << "] is " << hours;
	cout << "\nNumber of Minutes in Year [" << year << "] is " << minutes;
	cout << "\nNumber of Seconds in Year [" << year << "] is " << seconds;
}

int main()
{
	short year;
	cout << "Enter a year: ";
	cin >> year;
	PrintYearFormated(year);
	cout << endl;
	return 0;
}
