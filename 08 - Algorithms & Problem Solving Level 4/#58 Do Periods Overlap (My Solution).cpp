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

short GetMonthDays(short year, short month)
{
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (IsLeapYear(year) ? 29 : 28) : MonthsDays[month - 1];
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

	// else return true (yes they overlap)
	return true;
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

		if (DoPeriodsOverlap(period1, period2))
			cout << "Yes, they overlap.\n";
		else cout << "No, they don't overlap.\n";
		system("pause>0");
	} while (true);

	return 0;
}
