// Check For Palindrome Number
// https://programmingadvices.com/courses/1811531/lectures/41327662/comments/25774652

#include <iostream>

using namespace std;

string Reverse(string n)
{
	string reversed;
	for (int i = n.length() - 1; i >= 0; i--)
		reversed += n[i];
	return reversed;
}

int main()
{
	string n;
	cout << "Check If A Number Is Palindrome: ";
	cin >> n;

	if (Reverse(n) == n) cout << "\nYes, it is a Palindrome number.\n";
	else cout << "\nNo, it is NOT a Palindrome number.\n";
}