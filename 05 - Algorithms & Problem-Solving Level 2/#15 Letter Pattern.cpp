// Letter Pattern
// https://programmingadvices.com/courses/1811531/lectures/41358862/comments/25774950

#include <iostream>

using namespace std;

void LetterPattern(int n)
{
	for (int i = 1; i <= n; i++)
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
	LetterPattern(n);
}