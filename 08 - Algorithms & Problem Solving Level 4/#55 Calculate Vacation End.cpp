// #55 Calculate Vacation End
// https://programmingadvices.com/courses/1890122/lectures/47046525/comments/25882535

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

bool IsWeekend(short dayIndex)
{
	// Friday and Saturday
	return dayIndex == 5 || dayIndex == 6;
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

stDate CalcVacationEnd(stDate vacationStart, short vacationDays)
{
	short dayIndex = GetDayIndex(vacationStart);
	short vacationPeriod = vacationDays;

	for (short i = 1; i <= vacationPeriod; i++)
	{
		if (IsWeekend(dayIndex)) vacationPeriod++;
		if (++dayIndex > 6) dayIndex = 0;
	}

	return AddDaysToDate(vacationStart, vacationPeriod);
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
	printf("Vacation Start\n");
	stDate vacationStart = ReadDate();

	short vacationDays;
	printf("\nEnter Vacation Days: ");
	cin >> vacationDays;

	stDate vacationEnd = CalcVacationEnd(vacationStart, vacationDays);
	printf("\nReturn Date: %s, %02d/%02d/%d\n",
		GetDayName(GetDayIndex(vacationEnd)).c_str(),
		vacationEnd.day, vacationEnd.month, vacationEnd.year);

	return 0;
}
