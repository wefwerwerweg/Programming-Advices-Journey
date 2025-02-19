// #8 Month Calendar
// https://programmingadvices.com/courses/1890122/lectures/42994274/comments/25866016

#include <iostream>

using namespace std;

enum enDateInputs {YearIn, MonthIn, DayIn};

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

short GetDayIndex(short year, short month, short day)
{
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short dayIndex)
{
	string DaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysNames[dayIndex];
}

string GetMonthName(short month)
{
	string MonthsNames[12] = { "Jan", "Feb", "Mar", "Apr",
	"May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return MonthsNames[month - 1];
}

short GetMonthDays(short year, short month)
{
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
}

void MonthCalendar(short year, short month)
{
	short  dayIndex  = GetDayIndex(year, month, 1);
	short  monthDays = GetMonthDays(year, month);
	string monthName = GetMonthName(month);

	printf("\n ______________%s________________\n\n", monthName.c_str());
	printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	for (short i = 0; i < dayIndex; i++) printf("     ");
	for (short i = 1; i <= monthDays; i++)
	{
		printf(" %3d ", i);
		if ((dayIndex + i) % 7 == 0) printf("\n");
	}
	printf("\n _________________________________\n\n");
}

int main()
{
	cout << "Enter a year : ";
	short year = DateInput(enDateInputs::YearIn);
	cout << "Enter a month: ";
	short month = DateInput(enDateInputs::MonthIn);
	MonthCalendar(year, month);
	return 0;
}
