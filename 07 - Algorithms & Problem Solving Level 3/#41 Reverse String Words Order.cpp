// #41 Reverse String Words Order
// https://programmingadvices.com/courses/1869980/lectures/42839655/comments/25851696

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitString(string text, string delim = " ")
{
	string sWord; // define a string variable & delimiter
	vector<string> tokens;
	short pos;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos); // store the word
		if (sWord != "") tokens.push_back(sWord);
		text.erase(0, pos + delim.length()); // erase() until positon and move to next word.
	}
	if (text != "") tokens.push_back(text); // include last word of the string.
	return tokens;
}

string ReverseString(string text)
{
	vector<string> words = SplitString(text);
	vector<string>::iterator iter = words.end();
	text.clear();
	while (iter != words.begin())
		text += *--iter + " ";
	return text.substr(0, text.length() - 1); //remove last space.
}

int main()
{
	string text;
	cout << "Please Enter Your String:\n";
	getline(cin, text);
	text = ReverseString(text);
	cout << "String After Reverse:\n" << text << endl;
	return 0;
}
