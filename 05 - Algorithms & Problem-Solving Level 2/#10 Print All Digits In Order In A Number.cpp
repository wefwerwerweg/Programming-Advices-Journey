// Print All Digits In Order In A Number
// https://programmingadvices.com/courses/1811531/lectures/41327515/comments/25773346

#include <iostream>

using namespace std;

void PrintInOrder(string n)
{
	for (int i = 0; i < n.length(); i++)
		cout << n[i] << endl;
}

int main()
{
	string n;
	cout << "Print Numbers In Order In: ";
	cin >> n;
	PrintInOrder(n);
}