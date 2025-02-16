// #28 Invert All Characters Cases
// https://programmingadvices.com/courses/1869980/lectures/42655629/comments/25844071

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string InvertStringCase(string text)
{
	for (short i = 0; i < text.length(); i++)
		text[i] =  isupper(text[i]) ? tolower(text[i]) : toupper(text[i]);
	return text;
}

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nString after inverting all characters cases:\n";
	cout << InvertStringCase(text) << endl;
	return 0;
}
