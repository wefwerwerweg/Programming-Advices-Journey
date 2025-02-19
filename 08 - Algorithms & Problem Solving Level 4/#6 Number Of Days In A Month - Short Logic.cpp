// #6 Number Of Days In A Month - Short Logic
// https://programmingadvices.com/courses/1890122/lectures/42994272/comments/25862596

#include <iostream>
#include <string>

using namespace std;

bool IsLeapYear(short year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void PrintMonthFormated(short year, short month)
{
	short MonthsDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	short days = month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
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
