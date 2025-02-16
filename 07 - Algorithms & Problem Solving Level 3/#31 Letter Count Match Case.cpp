// #31 Letter Count Match Case
// https://programmingadvices.com/courses/1869980/lectures/42658721/comments/25844842

#include <iostream>
#include <string>

using namespace std;

char InvertCharacterCase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

short LetterCount(string text, char c, bool matchCase = true)
{
	short count = 0;

	for (short i = 0; i < text.length(); i++)
	{
		if (matchCase)
		{
			if (text[i] == c) count++;
		}
		else
		{
			if (tolower(text[i]) == tolower(c)) count++;
		}
	}

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
	cout << "Letter '" << c << "' OR '" << InvertCharacterCase(c) << "' count = " << LetterCount(text, c, false) << endl;
	return 0;
}
