// #65 Format Date
// https://programmingadvices.com/courses/1890122/lectures/43153487/comments/25895147

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	short year;
	short month;
	short day;
};

vector<string> SplitString(string text, string delim)
{
	string sWord; // define a string variable & delimiter
	vector<string> vWords;
	short pos;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos); // store the word
		if (sWord != "") vWords.push_back(sWord);
		text.erase(0, pos + delim.length()); // erase() until positon and move to next word.
	}
	if (text != "") vWords.push_back(text); // include last word of the string.
	return vWords;
}

stDate StringToDate(string dateString)
{
	stDate date; 
	vector <string> vDate;
	vDate = SplitString(dateString, "/");
	date.day = stoi(vDate[0]);
	date.month = stoi(vDate[1]);
	date.year = stoi(vDate[2]);
	return date;
}

string ReplaceStringWords(string text, string oldWord, string newWord)
{
	short pos = text.find(oldWord);
	while (pos != std::string::npos)
	{
		text = text.replace(pos, oldWord.length(), newWord);
		pos = text.find(oldWord); // find next
	}
	return text;
}

string FormatDate(stDate date, string format = "dd/mm/yyyy")
{
	format = ReplaceStringWords(format, "dd", to_string(date.day));
	format = ReplaceStringWords(format, "mm", to_string(date.month));
	format = ReplaceStringWords(format, "yyyy", to_string(date.year));
	return format;
}

int main()
{
	string dateString;
	cout << "\nEnter Date [dd/mm/yyyy]: ";
	cin >> dateString;
	stDate date = StringToDate(dateString);
	cout << endl << FormatDate(date, "dd-mm-yyyy") << endl;
	return 0;
}
