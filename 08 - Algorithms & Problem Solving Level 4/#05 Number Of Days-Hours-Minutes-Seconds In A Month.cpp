// #5 Number Of Days-Hours-Minutes-Seconds In A Month
// https://programmingadvices.com/courses/1890122/lectures/42994256/comments/25862565

#include <iostream>

using namespace std;

bool IsLeapYear(short year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void PrintMonthFormated(short year, short month)
{
	short days;
	if (month == 2) days = IsLeapYear(year) ? 29 : 28;
	else
	{
		bool ifBreak = false;
		short monthsOf31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 0; i < 7; i++)
		{
			if (monthsOf31Days[i] == month)
			{
				days = 31;
				ifBreak = true;
				break;
			}
		}
		if (!ifBreak) days = 30;
	}

	short hours = days * 24;
	int minutes = hours * 60;
	int seconds = minutes * 60;
	cout << "\nNumber of Days    in Month [" << month << "] is " << days;
	cout << "\nNumber of Hours   in Month [" << month << "] is " << hours;
	cout << "\nNumber of Minutes in Month [" << month << "] is " << minutes;
	cout << "\nNumber of Seconds in Month [" << month << "] is " << seconds;
}

int main()
{
	short year, month;
	cout << "Enter a year: ";
	cin >> year;
	cout << "Enter a month: ";
	cin >> month;
	PrintMonthFormated(year, month);
	cout << endl;
	return 0;
}
