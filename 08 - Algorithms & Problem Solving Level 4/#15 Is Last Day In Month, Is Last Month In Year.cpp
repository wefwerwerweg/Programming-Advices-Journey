// #15 Is Last Day In Month, Is Last Month In Year
// https://programmingadvices.com/courses/1890122/lectures/43070683/comments/25868295

#include <iostream>

using namespace std;

struct stDate
{
	short year;
	short month;
	short day;
};

bool IsLeapYear(short year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short GetMonthDays(short year, short month)
{
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
}

bool IsLastDayInMonth(stDate date)
{
	return date.day == GetMonthDays(date.year, date.month);
}

bool IsLastMonthInYear(short month)
{
	return month == 12;
}

short ShortInput()
{
	short input;
	cin >> input;
	while (cin.fail() || input < 1)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input! Enter a valid one: ";
		cin >> input;
	}
	return input;
}

short MonthInput()
{
	short input = ShortInput();
	while (input > 12)
	{
		cout << "Invalid input! Enter a valid one: ";
		input = ShortInput();
	}
	return input;
}

short DayInput(short year, short month)
{
	short input = ShortInput();
	while (input > GetMonthDays(year, month))
	{
		cout << "Invalid input! Enter a valid one: ";
		input = ShortInput();
	}
	return input;
}

stDate ReadDate()
{
	stDate date;
	cout << "Enter a year : ";
	date.year = ShortInput();
	cout << "Enter a month: ";
	date.month = MonthInput();
	cout << "Enter a day  : ";
	date.day = DayInput(date.year, date.month);
	return date;
}

int main()
{
	stDate date = ReadDate();
	if (IsLastDayInMonth(date))
		cout << "\nYes, Day is the last day in month.\n";
	else cout << "\nNo, Day is NOT the last day in month.\n";
	if (IsLastMonthInYear(date.month))
		cout << "Yes, Month is the last month in year.\n";
	else cout << "No, Month is NOT the last month in year.\n";
	return 0;
}
