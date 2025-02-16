// #30 Letter Count
// https://programmingadvices.com/courses/1869980/lectures/42658373/comments/25844127

#include <iostream>
#include <string>

using namespace std;

int LetterCount(string text, char c)
{
	short count = 0;
	for (short i = 0; i < text.length(); i++)
		if (text[i] == c) count++;
	return count;
}

int main()
{
	string text;
	char c;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nPlease enter a character:\n";
	cin >> c;
	cout << "\nLetter '" << c << "' count = " << LetterCount(text, c) << endl;
	return 0;
}
