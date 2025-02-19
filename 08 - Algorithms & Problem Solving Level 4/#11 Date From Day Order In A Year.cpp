// #11 Date From Day Order In A Year
// https://programmingadvices.com/courses/1890122/lectures/43069142/comments/25866676

#include <iostream>
#include <string>

using namespace std;

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

string GetDateFromDayOrder(short year, short numOfDays)
{
	short month;
	for (month = 1; month <= 12; month++)
	{
		short monthDays = GetMonthDays(year, month);
		if (monthDays < numOfDays)
		{
			numOfDays -= monthDays;
			continue;
		}
		break;
	}
	return to_string(numOfDays) + "/" + to_string(month) + "/" + to_string(year);
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
	cout << "Enter a year : ";
	short year = ShortInput();
	cout << "Enter a month: ";
	short month = MonthInput();
	cout << "Enter a day  : ";
	short day = DayInput(year, month);

	short numOfDays = NumOfDaysSinceYearBegan(year, month, day);
	cout << "\nNumber of days from the beginning of the year is ";
	cout << numOfDays;
	cout << "\n\nDate For [" << numOfDays << "] is: ";
	cout << GetDateFromDayOrder(year, numOfDays) << endl;
	return 0;
}
