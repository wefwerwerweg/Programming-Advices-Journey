// #54 Calculate Vacation Days
// https://programmingadvices.com/courses/1890122/lectures/43136729/comments/25881525

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

bool IsBusinessDay(short dayIndex)
{
	return !IsWeekend(dayIndex);
}

bool IsDate1LessThanDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) 
		|| (date1.year == date2.year && date1.month < date2.month) 
		|| (date1.year == date2.year && date1.month == date2.month
			&& date1.day < date2.day);
}

bool AreDatesEqual(stDate date1, stDate date2)
{
	return date1.year == date2.year
		&& date1.month == date2.month
		&& date1.day == date2.day;
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

int DatesDiffInDays(stDate date1, stDate date2, bool includeEndDay = false)
{
	if (!IsDate1LessThanDate2(date1, date2)
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

short CalcVacationDays(stDate vacationStart, stDate vacationEnd)
{
	short vacationPeriod = DatesDiffInDays(vacationStart, vacationEnd);
	short dayIndex = GetDayIndex(vacationStart);
	short actualVacationDays = 0;

	for (; vacationPeriod > 0; vacationPeriod--)
	{
		if (IsBusinessDay(dayIndex)) actualVacationDays++;
		if (++dayIndex > 6) dayIndex = 0;
	}

	return actualVacationDays;
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
	printf("\nVacation End\n");
	stDate vacationEnd = ReadDate();

	printf("\nVacation From: %s, %02d/%02d/%d",
		GetDayName(GetDayIndex(vacationStart)).c_str(),
		vacationStart.day, vacationStart.month, vacationStart.year);
	printf("\nVacation To  : %s, %02d/%02d/%d",
		GetDayName(GetDayIndex(vacationEnd)).c_str(),
		vacationEnd.day, vacationEnd.month, vacationEnd.year);

	printf("\n\nActual Vacation Days: %d day(s).\n", 
		CalcVacationDays(vacationStart, vacationEnd));

	return 0;
}
