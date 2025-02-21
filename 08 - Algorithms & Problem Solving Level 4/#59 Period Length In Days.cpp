// #59 Period Length In Days
// https://programmingadvices.com/courses/1890122/lectures/43138499/comments/25882937

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

int DatesDiffInDays(stDate date1, stDate date2, bool includeEndDay = false)
{
	if (!IsDate1BeforeDate2(date1, date2)
		&& !AreDatesEqual(date1, date2))
		return -DatesDiffInDays(date2, date1, includeEndDay);

	int diffInDays = 0;

	while (true)
	{
		short date1DaysPassed = NumOfDaysSinceYearBegan(date1);
		short date1YearDays = IsLeapYear(date1.year) ? 366 : 365;
		short date1MonthDays = GetMonthDays(date1.year, date1.month);

		if (date2.year > date1.year)
		{
			diffInDays += (date1YearDays - date1DaysPassed) + 1;
			date1.day = 1;
			date1.month = 1;
			date1.year++;
		}
		else if (date2.month > date1.month)
		{
			diffInDays += (date1MonthDays - date1.day) + 1;
			date1.day = 1;
			date1.month++;
		}
		else
		{
			diffInDays += (date2.day - date1.day);
			date1.day = date2.day;
			break;
		}
	}

	return includeEndDay ? ++diffInDays : diffInDays;
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

	cout << "\nPeriod length is: ";
	cout << DatesDiffInDays(period.start, period.end);

	cout << "\nPeriod length (including end date) is: ";
	cout << DatesDiffInDays(period.start, period.end, true);
	cout << endl;

	return 0;
}
