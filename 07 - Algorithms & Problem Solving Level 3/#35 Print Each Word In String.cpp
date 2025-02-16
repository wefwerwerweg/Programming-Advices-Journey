// #35 Print Each Word In String
// https://programmingadvices.com/courses/1869980/lectures/42663250/comments/25845134

#include <iostream>
#include <string>

using namespace std;

void PrintWords(string text)
{
	string word = "";
	for (char c : text)
	{
		if (c != ' ')
		{
			word += c;
		}
		else if (word != "")
		{
			cout << word << endl;
			word = "";
		}
	}
	// Make sure last word is printed.
	if (word != "") cout << word << endl;
}

/*
	// Instructor Solution:

	void PrintEachWordInString(string S1)
	{
		string sWord, delim = " "; // define a string variable & delimiter
		short pos = 0;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "") cout << sWord << endl;
			S1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
		}
		if (S1 != "")
			cout << S1 << endl; // it print last word of the string.
	}
*/

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nWords in string are:\n";
	PrintWords(text);
	return 0;
}
