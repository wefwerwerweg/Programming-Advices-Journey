// #36 Count Each Word In String
// https://programmingadvices.com/courses/1869980/lectures/42663382/comments/25845196

#include <iostream>
#include <string>

using namespace std;

short CountWords(string text)
{
	short count = 0;
	if (text[0] != ' ') count++;
	for (short i = 1; i < text.length(); i++)
		if (text[i] != ' ' && text[i - 1] == ' ') count++;
	return count;
}

/* Instructor Solution:
short CountWords(string S1)
{
	string delim = " "; // delimiter
	short Counter = 0;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			Counter++;
		}
		//erase() until positon and move to next word.
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
	{
		Counter++; // it counts the last word of the string.
	}
	return Counter;
}
*/

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nWords count in string is: " << CountWords(text) << endl;
	return 0;
}
