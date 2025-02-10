// Print Digits In A Reversed Order In A Number
// https://programmingadvices.com/courses/1811531/lectures/41306881/comments/25772509

#include <iostream>

using namespace std;

void PrintReversed(string n)
{
	for (int i = n.length() - 1; i >= 0; i--)
		cout << n[i];
}

int main()
{
	string n;
	cout << "Print Numbers In Reversed Order In: ";
	cin >> n;
	PrintReversed(n);
}