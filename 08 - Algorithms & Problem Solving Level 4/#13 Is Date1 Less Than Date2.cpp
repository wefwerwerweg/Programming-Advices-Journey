// #13 Is Date1 Less Than Date2
// https://programmingadvices.com/courses/1890122/lectures/43069887/comments/25868146

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

bool IsDate1LessThanDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : 
		((date1.year == date2.year) ? (date1.month < date2.month ? true :
			(date1.month == date2.month ? date1.day < date2.day : false)) : false);
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
	stDate date1 = ReadDate();
	cout << endl;
	stDate date2 = ReadDate();
	if (IsDate1LessThanDate2(date1, date2))
		cout << "\nYes, Date1 is less than Date2.\n";
	else cout << "\nNo, Date1 is NOT less than Date2.\n";
	return 0;
}
