// #24 Upper First Letter Of Each Word
// https://programmingadvices.com/courses/1869980/lectures/42568833/comments/25843980

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string UpperFirstLetterOfEachWord(string text)
{
	if (islower(text[0])) text[0] = toupper(text[0]);

	for (int i = 1; i < text.length(); i++)
	{
		if (islower(text[i]) && text[i - 1] == ' ')
			text[i] = toupper(text[i]);
	}

	return text;
}

int main()
{
	string text;
	cout << "Please enter your string:\n";
	getline(cin, text);
	cout << "\nUpper first letter of each word:\n";
	cout << UpperFirstLetterOfEachWord(text);
	return 0;
}
