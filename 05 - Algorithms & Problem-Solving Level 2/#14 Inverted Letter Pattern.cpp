// Inverted Letter Pattern
// https://programmingadvices.com/courses/1811531/lectures/41358733/comments/25774905

#include <iostream>

using namespace std;

void InvertedLetterPattern(int n)
{
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++) cout << char(i + 64);
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Enter Number Of Letters: ";
	cin >> n;
	cout << endl;
	InvertedLetterPattern(n);
}