// #61 Count Overlap Days (My Long Solution)
// https://programmingadvices.com/courses/1890122/lectures/43139320/comments/25894850

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

int PeriodLength(stPeriod period, bool includeEndDay = false)
{
	return DatesDiffInDays(period.start, period.end, includeEndDay);
}

bool IsDateWithinPeriod(stDate date, stPeriod period)
{
	return (IsDate1AfterDate2(date, period.start)
		&& IsDate1BeforeDate2(date, period.end));
}

bool ArePeriodsEqual(stPeriod period1, stPeriod period2)
{
	return (AreDatesEqual(period1.start, period2.start)
		&& AreDatesEqual(period1.end, period2.end));
}

// for explaination: period1 is: [], period2 is: <>.
// overlap true:
// case1: [<>]
// case2: <[]>
// case3: [<]>
// case4: <[>]
// case5: [] == <>
// 
// overlap false:
// case1: [] <>
// case2: <> []
// 
// 2 checks are easier than 5 checks, right?
bool DoPeriodsOverlap(stPeriod period1, stPeriod period2)
{
	// if [] <> return false
	if (IsDate1BeforeDate2(period1.start, period2.start)
		&& IsDate1BeforeDate2(period1.end, period2.start))
		return false;

	// if <> [] return false
	if (IsDate1AfterDate2(period1.start, period2.end)
		&& IsDate1AfterDate2(period1.end, period2.end))
		return false;

	// |  [ ]|
	// |< >  |  return false
	if (IsDate1BeforeDate2(period2.start, period1.start)
		&& AreDatesEqual(period2.end, period1.start))
		return false;

	// |[ ]  |
	// |  < >|  return false
	if (IsDate1AfterDate2(period2.end, period1.end)
		&& AreDatesEqual(period2.start, period1.end))
		return false;

	// else return true (yes they overlap)
	return true;
}

// for explaination: period1 is: [], period2 is: <>.
short CountOverlapDays(stPeriod period1, stPeriod period2)
{
	if (!DoPeriodsOverlap(period1, period2)) return 0;

	// case1:  [ < > ]  OverlapDays = period2 length
	if (IsDateWithinPeriod(period2.start, period1)
		&& IsDateWithinPeriod(period2.end, period1))
		return PeriodLength(period2);

	// case2:  < [ ] >  OverlapDays = period1 length
	if (IsDateWithinPeriod(period1.start, period2)
		&& IsDateWithinPeriod(period1.end, period2))
		return PeriodLength(period1);

	// case3:  [ < ] >  OverlapDays = days between period2 start and period1 end
	if (IsDateWithinPeriod(period2.start, period1)
		&& IsDate1AfterDate2(period2.end, period1.end))
		return DatesDiffInDays(period2.start, period1.end);

	// case4:  < [ > ]  OverlapDays = days between period1 start and period2 end
	if (IsDateWithinPeriod(period1.start, period2)
		&& IsDate1AfterDate2(period1.end, period2.end))
		return DatesDiffInDays(period1.start, period2.end);

	// case5: Periods' start & end dates are the same | [ ] |
	// OverlapDays = period1 length or period2 length | < > |
	if (ArePeriodsEqual(period1, period2))
		return PeriodLength(period1);

	// cases 6,7,8,9: Periods have the same start OR end date
	if (AreDatesEqual(period1.start, period2.start))
	{
		if (IsDateWithinPeriod(period2.end, period1))   // | [   ] |
			return PeriodLength(period2);               // | < >   |

		else										    // | [ ]   |
			return PeriodLength(period1);			    // | <   > |
	}
	else // Period1 & Period2 have same end date
	{
		if (IsDateWithinPeriod(period2.start, period1)) // | [   ] |
			return PeriodLength(period2);				// |   < > |

		else											// |   [ ] |
			return PeriodLength(period1);				// | <   > |
	}

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

short YearInput()
{
	short input = ShortInput();
	while (input > 9999)
	{
		cout << "Max is 9999! Try again: ";
		input = ShortInput();
	}
	return input;
}

short MonthInput()
{
	short input = ShortInput();
	while (input > 12)
	{
		cout << "Max is 12! Try again: ";
		input = ShortInput();
	}
	return input;
}


short DayInput(short year, short month)
{
	short input = ShortInput();
	short monthDays = GetMonthDays(year, month);
	while (input > monthDays)
	{
		printf("Max is %d! Try again: ", monthDays);
		input = ShortInput();
	}
	return input;
}

stDate ReadDate()
{
	stDate date;
	cout << "Enter a year : ";
	date.year = YearInput();
	cout << "Enter a month: ";
	date.month = MonthInput();
	cout << "Enter a day  : ";
	date.day = DayInput(date.year, date.month);
	return date;
}

stPeriod ReadPeriod(short periodNum = 0)
{
	stPeriod period;
	cout << "Enter Period ";
	if (periodNum) cout << periodNum;

	cout << "\n\nEnter start date\n";
	period.start = ReadDate();

	cout << "\nEnter end date\n";
	period.end = ReadDate();

	while (!IsDate1AfterDate2(period.end, period.start))
	{
		cout << "ERROR: Period end date must be after period start date.\n";
		cout << "\nEnter end date\n";
		period.end = ReadDate();
	}

	return period;
}

int main()
{
	do
	{
		system("cls");
		printf("\n");

		stPeriod period1 = ReadPeriod(1);
		printf("------------------------\n");
		printf("%02d/%02d/%04d To %02d/%02d/%04d",
			period1.start.day, period1.start.month, period1.start.year,
			period1.end.day, period1.end.month, period1.end.year);
		printf("\n------------------------\n\n");

		stPeriod period2 = ReadPeriod(2);
		printf("------------------------\n");
		printf("%02d/%02d/%04d To %02d/%02d/%04d",
			period2.start.day, period2.start.month, period2.start.year,
			period2.end.day, period2.end.month, period2.end.year);
		printf("\n------------------------\n\n");

		printf("Overlap Days Count: %d\n", CountOverlapDays(period1, period2));
		system("pause>0");
	} while (true);

	return 0;
}
