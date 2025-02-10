// Reverse A Number
// https://programmingadvices.com/courses/1811531/lectures/41327443/comments/25772973

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
	cout << "Enter A Number To Reverse: ";
	cin >> n;
	cout << "Reverse Is: " << Reverse(n);
}