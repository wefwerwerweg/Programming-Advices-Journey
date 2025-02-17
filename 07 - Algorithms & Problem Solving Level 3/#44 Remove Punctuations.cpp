// #44 Remove Punctuations
// https://programmingadvices.com/courses/1869980/lectures/42840283/comments/25852011

#include <iostream>
#include <string>

using namespace std;

string RemovePunct(string text)
{
	string noPunct = "";
	for (char c : text)
		if (!ispunct(c)) noPunct += c;
	return noPunct;
}

int main()
{
	string text;
	cout << "Please Enter Your String:\n";
	getline(cin, text);
	cout << "\nPunctuations Removed:\n";
	cout << RemovePunct(text);
	return 0;
}
