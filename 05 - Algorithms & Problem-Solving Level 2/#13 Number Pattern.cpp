// Number Pattern
// https://programmingadvices.com/courses/1811531/lectures/41358716/comments/25774778

#include <iostream>

using namespace std;

void Pattern(int n)
{
	for (int i = 1; i <= n; i++)
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
	Pattern(n);
}