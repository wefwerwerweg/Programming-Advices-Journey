// #63 & #64 Read & Print Date String
// https://programmingadvices.com/courses/1890122/lectures/43152843/comments/25895056

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

string DateToString(stDate date)
{
	return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
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

int main()
{
	string dateString;
	cout << "\nEnter Date [dd/mm/yyyy]: ";
	cin >> dateString;
	stDate date = StringToDate(dateString);
	cout << "\nDay  : " << date.day << endl;
	cout << "Month: " << date.month << endl;
	cout << "Year : " << date.year << endl;
	cout << "\nYou Entered: " << DateToString(date) << "\n";
	return 0;
}
