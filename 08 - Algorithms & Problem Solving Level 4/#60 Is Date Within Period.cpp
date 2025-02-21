// #60 Is Date Within Period
// https://programmingadvices.com/courses/1890122/lectures/43138924/comments/25883305

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

bool IsDateWithinPeriod(stPeriod period, stDate date)
{
	return (IsDate1AfterDate2(date, period.start)
		&& IsDate1BeforeDate2(date, period.end));
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
	stPeriod period;
	cout << "Enter Period\n\n";
	cout << "Enter start date\n";
	period.start = ReadDate();
	cout << "\nEnter end date\n";
	period.end = ReadDate();
	cout << "----------------\n";

	cout << "\nEnter Date\n";
	stDate date = ReadDate();

	if (IsDateWithinPeriod(period, date))
		cout << "\nYes, date is within period\n";
	else cout << "\nNo, date is not within period\n";

	return 0;
}
