// Inverted Number Pattern
// https://programmingadvices.com/courses/1811531/lectures/41327692/comments/25774742

#include <iostream>

using namespace std;

void InvertedPattern(int n)
{
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++) cout << i;
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Enter A Number: ";
	cin >> n;
	cout << endl;
	InvertedPattern(n);
}