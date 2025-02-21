// #57 Dates Compare Function
// https://programmingadvices.com/courses/1890122/lectures/43137806/comments/25882657

#include <iostream>

using namespace std;

enum enDateCompare {Before = -1, Equal = 0, After = 1};

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

bool IsDate1BeforeDate2(stDate date1, stDate date2)
{
	if (date1.year < date2.year) return true;
	else if (date1.month < date2.month) return true;
	else if (date1.day < date2.day) return true;
	return false;
}

bool AreDatesEqual(stDate date1, stDate date2)
{
	return date1.year == date2.year
		&& date1.month == date2.month
		&& date1.day == date2.day;
}

bool IsDate1AfterDate2(stDate date1, stDate date2)
{
	if (date1.year > date2.year) return true;
	else if (date1.month > date2.month) return true;
	else if (date1.day > date2.day) return true;
	return false;
}

enDateCompare CompareDates(stDate date1, stDate date2)
{
	if (IsDate1BeforeDate2(date1, date2))
		return enDateCompare::Before;
	else if (AreDatesEqual(date1, date2))
		return enDateCompare::Equal;
	else
		return enDateCompare::After;
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
	cout << "Enter Date1\n";
	stDate date1 = ReadDate();

	cout << "\nEnter Date2\n";
	stDate date2 = ReadDate();

	if (IsDate1AfterDate2(date1, date2))
		cout << "\nYes, Date1 is after Date2.\n";
	else cout << "\nNo, Date1 is not after Date2.\n";

	return 0;
}
