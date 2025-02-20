// #20 To #32 Increase Date Problems
// https://programmingadvices.com/courses/1890122/lectures/43108158/comments/25874400

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

stDate AddYearsToDate(stDate date, short yearsToAdd)
{
	date.year += yearsToAdd;
	if (!IsLeapYear(date.year) && date.month == 2 && date.day == 29)
		date.day = 28;
	return date;
}

stDate AddMonthsToDate(stDate date, short monthsToAdd)
{
	short monthsToYears = monthsToAdd / 12;
	if (monthsToYears > 0)
	{
		date = AddYearsToDate(date, monthsToYears);
		monthsToAdd %= 12;
	}

	short monthsLeftInTheYear = 12 - date.month;
	if (monthsToAdd > monthsLeftInTheYear)
	{
		date.year++;
		date.month = monthsToAdd - monthsLeftInTheYear;
	}
	else date.month += monthsToAdd;

	short monthDays = GetMonthDays(date.year, date.month);
	if (date.day > monthDays) date.day = monthDays;

	return date;
}

stDate AddDaysToDate(stDate date, short daysToAdd)
{
	while (daysToAdd != 0)
	{
		short daysPassedSinceYearBegan = NumOfDaysSinceYearBegan(date);
		short yearDays = IsLeapYear(date.year) ? 366 : 365;
		short monthDays = GetMonthDays(date.year, date.month);

		if (daysToAdd + daysPassedSinceYearBegan > yearDays)
		{
			daysToAdd = daysToAdd - (yearDays - daysPassedSinceYearBegan) - 1;
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else if (daysToAdd + date.day > monthDays)
		{
			daysToAdd = daysToAdd - (monthDays - date.day) - 1;
			date.day = 1;
			date.month++;
		}
		else
		{
			date.day += daysToAdd;
			daysToAdd = 0;
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
	date = AddDaysToDate(date, 1);
	printf("\n01-Adding one day is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddDaysToDate(date, 10);
	printf("\n02-Adding 10 days is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddDaysToDate(date, 7);
	printf("\n03-Adding one week is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddDaysToDate(date, 10 * 7);
	printf("\n04-Adding 10 weeks is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddMonthsToDate(date, 1);
	printf("\n05-Adding one month is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddMonthsToDate(date, 5);
	printf("\n06-Adding 5 months is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 1);
	printf("\n07-Adding one year is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 10);
	printf("\n08-Adding 10 years is: %02d/%02d/%d", date.day, date.month, date.year);
	//date = AddYearsToDate(date, 10);
	//printf("\n09-Adding 10 Years (faster) is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 10);
	printf("\n10-Adding one decade is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 10 * 10);
	printf("\n11-Adding 10 decades is: %02d/%02d/%d", date.day, date.month, date.year);
	//date = AddYearsToDate(date, 10 * 10);
	//printf("\n12-Adding 10 Decades (faster) is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 100);
	printf("\n13-Adding one century is: %02d/%02d/%d", date.day, date.month, date.year);
	date = AddYearsToDate(date, 1000);
	printf("\n14-Adding one millennium is: %02d/%02d/%d\n", date.day, date.month, date.year);
	return 0;
}
