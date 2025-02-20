// #33 To #46 Decrease Date Problems
// https://programmingadvices.com/courses/1890122/lectures/43108652/comments/25874664

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

short NumOfDaysSinceYearBegan(stDate date)
{
	short numOfDays = date.day;
	for (short i = 1; i < date.month; i++)
		numOfDays += GetMonthDays(date.year, i);
	return numOfDays;
}

stDate SubYearsFromDate(stDate date, short yearsToSub)
{
	date.year -= yearsToSub;
	if (!IsLeapYear(date.year) && date.month == 2 && date.day == 29)
		date.day = 28;
	return date;
}

stDate SubMonthsFromDate(stDate date, short monthsToSub)
{
	short monthsToYears = monthsToSub / 12;
	if (monthsToYears > 0)
	{
		date = SubYearsFromDate(date, monthsToYears);
		monthsToSub %= 12;
	}

	if (monthsToSub >= date.month)
	{
		date.year--;
		date.month = 12 - (monthsToSub - date.month);
	}
	else date.month -= monthsToSub;

	short monthDays = GetMonthDays(date.year, date.month);
	if (date.day > monthDays) date.day = monthDays;

	return date;
}

stDate SubDaysFromDate(stDate date, short daysToSub)
{
	while (daysToSub != 0)
	{
		short daysPassedSinceYearBegan = NumOfDaysSinceYearBegan(date);

		if (daysToSub >= daysPassedSinceYearBegan)
		{
			daysToSub -= daysPassedSinceYearBegan;
			date.year--;
			date.month = 12;
			date.day = 31;
		}
		else if (daysToSub >= date.day)
		{
			daysToSub -= date.day;
			date.month--;
			date.day = GetMonthDays(date.year, date.month);
		}
		else
		{
			date.day -= daysToSub;
			daysToSub = 0;
		}
	}

	return date;
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
	printf("\nDate After:\n");
	date = SubDaysFromDate(date, 1);
	printf("\n01-Subtracting one day is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubDaysFromDate(date, 10);
	printf("\n02-Subtracting 10 days is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubDaysFromDate(date, 7);
	printf("\n03-Subtracting one week is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubDaysFromDate(date, 10 * 7);
	printf("\n04-Subtracting 10 weeks is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubMonthsFromDate(date, 1);
	printf("\n05-Subtracting one month is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubMonthsFromDate(date, 5);
	printf("\n06-Subtracting 5 months is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 1);
	printf("\n07-Subtracting one year is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 10);
	printf("\n08-Subtracting 10 years is: %02d/%02d/%d", date.day, date.month, date.year);
	//date = AddYearsToDate(date, 10);
	//printf("\n09-Subtracting 10 Years (faster) is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 10);
	printf("\n10-Subtracting one decade is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 10 * 10);
	printf("\n11-Subtracting 10 decades is: %02d/%02d/%d", date.day, date.month, date.year);
	//date = AddYearsToDate(date, 10 * 10);
	//printf("\n12-Subtracting 10 Decades (faster) is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 100);
	printf("\n13-Subtracting one century is: %02d/%02d/%d", date.day, date.month, date.year);
	date = SubYearsFromDate(date, 1000);
	printf("\n14-Subtracting one millennium is: %02d/%02d/%d\n", date.day, date.month, date.year);
	return 0;
}
