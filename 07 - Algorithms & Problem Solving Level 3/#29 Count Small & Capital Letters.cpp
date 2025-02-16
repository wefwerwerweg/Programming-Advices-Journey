// #29 Count Small & Capital Letters
// https://programmingadvices.com/courses/1869980/lectures/42657741/comments/25844104

#include <iostream>
#include <string>

using namespace std;

int UpperCount(string text)
{
	short count = 0;
	for (short i = 0; i < text.length(); i++)
		if (isupper(text[i])) count++;
	return count;
}

int LowerCount(string text)
{
	short count = 0;
	for (short i = 0; i < text.length(); i++)
		if (islower(text[i])) count++;
	return count;
}

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nString Length: " << text.length() << endl;
	cout << "Capital Letters Count: " << UpperCount(text) << endl;
	cout << "Lower Letters Count: " << LowerCount(text) << endl;
	return 0;
}
