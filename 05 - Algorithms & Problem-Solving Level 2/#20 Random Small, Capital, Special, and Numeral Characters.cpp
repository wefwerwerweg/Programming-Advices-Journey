// Random Small, Capital, Special, and Numeral Characters.
// https://programmingadvices.com/courses/1811531/lectures/41359792/comments/25779774

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int main() {
	srand((unsigned) time(NULL));

	cout << char(RandomNumber(97, 122)) << endl;
	cout << char(RandomNumber(65, 90))  << endl;
	cout << char(RandomNumber(33, 47))  << endl;
	cout <<		 RandomNumber(0, 9)     << endl;
}