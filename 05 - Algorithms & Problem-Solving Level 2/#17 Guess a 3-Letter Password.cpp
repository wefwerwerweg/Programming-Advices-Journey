// Guess a 3-Letter Password
// https://programmingadvices.com/courses/1811531/lectures/41359449/comments/25775763

#include <iostream>

using namespace std;

void GuessPassword(string pass)
{
	int trials = 0;

	for (char i = 'A'; i <= 'Z'; i++)
		for (char j = 'A'; j <= 'Z'; j++)
			for (char k = 'A'; k <= 'Z'; k++)
			{
				cout << "Trial [" << ++trials << "]: " << i << j << k << endl;

				if (pass[0] == i && pass[1] == j && pass[2] == k)
				{
					cout << "\nPassword Is " << i << j << k;
					cout << "\nFound After " << trials << " Trial(s)" << endl;
					return;
				}
			}
}

int main()
{
	string pass;
	cout << "Enter a 3-Letter Uppercase Password: ";
	cin >> pass;
	cout << endl;
	GuessPassword(pass);
}