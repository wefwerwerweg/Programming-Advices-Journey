// #7 Day Name
// https://programmingadvices.com/courses/1890122/lectures/42994273/comments/25862653

#include <iostream>

using namespace std;

void PrintDate(short year, short month, short day)
{
	short a, y, m, dayIndex;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	dayIndex = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	string dayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	cout << "\nDate      : " << day << "/" << month << "/" << year;
	cout << "\nDate Order: " << dayIndex;
	cout << "\nDate Name : " << dayNames[dayIndex];
}

int main()
{
	short year, month, day;
	cout << "Enter a year : ";
	cin >> year;
	cout << "Enter a month: ";
	cin >> month;
	cout << "Enter a day  : ";
	cin >> day;
	PrintDate(year, month, day);
	cout << endl;
	return 0;
}
