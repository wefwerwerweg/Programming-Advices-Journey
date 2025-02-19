// #12 Add Days To Date
// https://programmingadvices.com/courses/1890122/lectures/43069428/comments/25868007

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

stDate AddDaysToDate(stDate date, short daysToAdd)
{
	while (daysToAdd != 0)
	{
		short daysPassed = NumOfDaysSinceYearBegan(date);
		short yearDays = IsLeapYear(date.year) ? 366 : 365;
		short monthDays = GetMonthDays(date.year, date.month);

		if (daysToAdd + daysPassed > yearDays)
		{
			daysToAdd = daysToAdd - (yearDays - daysPassed) - 1;
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

int main()
{
	stDate date;
	cout << "Enter a year : ";
	date.year = ShortInput();
	cout << "Enter a month: ";
	date.month = MonthInput();
	cout << "Enter a day  : ";
	date.day = DayInput(date.year, date.month);
	cout << "\nHow many days to add: ";
	short daysToAdd = ShortInput();

	date = AddDaysToDate(date, daysToAdd);

	printf("\nDate after adding [%d] days is: ", daysToAdd);
	printf("%02d/%02d/%d", date.day, date.month, date.year);
	printf("\n");
	return 0;
}
