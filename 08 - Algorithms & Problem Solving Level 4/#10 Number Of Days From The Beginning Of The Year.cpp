// #10 Number Of Days From The Beginning Of The Year
// https://programmingadvices.com/courses/1890122/lectures/42994275/comments/25866273

#include <iostream>

using namespace std;

enum enDateInputs { YearIn, MonthIn, DayIn };

short DateInput(enDateInputs type)
{
	short input;
	cin >> input;
	while (cin.fail() || input < 1
		|| (type == enDateInputs::DayIn && input > 31)
		|| (type == enDateInputs::MonthIn && input > 12))
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input! Enter a valid one: ";
		cin >> input;
	}
	return input;
}

bool IsLeapYear(short year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

short GetMonthDays(short year, short month)
{
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
}

short NumOfDaysSinceYearBegan(short year, short month, short day)
{
	short numOfDays = day;
	for (short i = 1; i < month; i++)
		numOfDays += GetMonthDays(year, i);
	return numOfDays;
}

int main()
{
	cout << "Enter a day  : ";
	short day = DateInput(enDateInputs::DayIn);
	cout << "Enter a month: ";
	short month = DateInput(enDateInputs::MonthIn);
	cout << "Enter a year : ";
	short year = DateInput(enDateInputs::YearIn);

	cout << "\nNumber of days from the beginning of the year is ";
	cout << NumOfDaysSinceYearBegan(year, month, day) << endl;
	return 0;
}
