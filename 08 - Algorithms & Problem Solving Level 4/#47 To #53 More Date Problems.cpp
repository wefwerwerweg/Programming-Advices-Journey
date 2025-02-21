// #47 To #53 More Date Problems
// https://programmingadvices.com/courses/1890122/lectures/43136394/comments/25881337

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

bool IsEndOfWeek(short dayIndex)
{
	return dayIndex == 6;
}

bool IsWeekend(short dayIndex)
{
	// Friday and Saturday
	return dayIndex == 5 || dayIndex == 6;
}

bool IsBusinessDay(short dayIndex)
{
	return !IsWeekend(dayIndex);
}

short GetDayIndex(stDate date)
{
	short a, y, m;
	a = (14 - date.month) / 12;
	y = date.year - a;
	m = date.month + (12 * a) - 2;
	return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short dayIndex)
{
	string DaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysNames[dayIndex];
}

short GetMonthDays(short year, short month)
{
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
}

stDate GetDateNow()
{
	stDate date;
	time_t t = time(0); // get time now
	tm* now = localtime(&t);
	date.year = now->tm_year + 1900;
	date.month = now->tm_mon + 1;
	date.day = now->tm_mday;
	return date;
}

short NumOfDaysSinceYearBegan(stDate date)
{
	short numOfDays = date.day;
	for (short i = 1; i < date.month; i++)
		numOfDays += GetMonthDays(date.year, i);
	return numOfDays;
}

short DaysUntilEndOfWeek(short dayIndex)
{
	return 6 - dayIndex;
}

short DaysUntilEndOfMonth(stDate date)
{
	return GetMonthDays(date.year, date.month) - date.day;
}

short DaysUntilEndOfYear(stDate date)
{
	return (IsLeapYear(date.year) ? 366 : 365) - NumOfDaysSinceYearBegan(date);
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
	stDate date = GetDateNow();
	short dayIndex = GetDayIndex(date);

	printf("Today is %s, %02d/%02d/%d", 
		GetDayName(dayIndex).c_str(),
		date.day, date.month, date.year);

	printf("\n\nIs it end of week?\n");
	if (IsEndOfWeek(dayIndex))
		printf("Yes, it is end of week.");
	else printf("No, it is not end of week.");

	printf("\n\nIs it a weekend?\n");
	if (IsWeekend(dayIndex))
		printf("Yes, it is a weekend.");
	else printf("No, it is not a weekend.");

	printf("\n\nIs it a business day?\n");
	if (IsBusinessDay(dayIndex))
		printf("Yes, it is a business day.");
	else printf("No, it is not a business day.");

	printf("\n\nDays until end of week  : %d day(s)",
		DaysUntilEndOfWeek(dayIndex));
	printf("\nDays until end of month : %d day(s)",
		DaysUntilEndOfMonth(date));
	printf("\nDays until end of year  : %d day(s)\n",
		DaysUntilEndOfYear(date));
}
