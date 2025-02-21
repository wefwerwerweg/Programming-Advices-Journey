// #58 Do Periods Overlap
// https://programmingadvices.com/courses/1890122/lectures/43138483/comments/25882837

#include <iostream>

using namespace std;

struct stDate
{
	short year;
	short month;
	short day;
};

struct stPeriod
{
	stDate start;
	stDate end;
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

bool IsDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) 
		|| (date1.year == date2.year && date1.month < date2.month) 
		|| (date1.year == date2.year && date1.month == date2.month
			&& date1.day < date2.day);
}

bool IsDate1AfterDate2(stDate date1, stDate date2)
{
	return (date1.year > date2.year)
		|| (date1.year == date2.year && date1.month > date2.month)
		|| (date1.year == date2.year && date1.month == date2.month
			&& date1.day > date2.day);
}

bool DoPeriodsOverlap(stPeriod period1, stPeriod period2)
{
	return (IsDate1BeforeDate2(period1.start, period2.end)
		|| IsDate1AfterDate2(period1.end, period2.start));
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
	stPeriod period1;
	cout << "Enter Period 1\n\n";
	cout << "Enter start date\n";
	period1.start = ReadDate();
	cout << "\nEnter end date\n";
	period1.end = ReadDate();
	cout << "----------------\n";

	stPeriod period2;
	cout << "\nEnter Period 2\n\n";
	cout << "Enter start date\n";
	period2.start = ReadDate();
	cout << "\nEnter end date\n";
	period2.end = ReadDate();
	cout << "----------------\n";

	if (DoPeriodsOverlap(period1, period2))
		cout << "\nYes, periods overlap.\n";
	else cout << "\nNo, periods don't overlap.\n";

	return 0;
}
