// #25 Lower First Letter Of Each Word

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string LowerFirstLetterOfEachWord(string text)
{
	if (isupper(text[0])) text[0] = tolower(text[0]);

	for (int i = 1; i < text.length(); i++)
	{
		if (isupper(text[i]) && text[i - 1] == ' ')
			text[i] = tolower(text[i]);
	}

	return text;
}

int main()
{
	string text;
	cout << "Please enter your string:\n";
	getline(cin, text);
	cout << "\nLower first letter of each word:\n";
	cout << LowerFirstLetterOfEachWord(text);
	return 0;
}
