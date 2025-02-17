// #40 Join String (Overloading)
// https://programmingadvices.com/courses/1869980/lectures/42697775/comments/25851429

#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector<string>& words, string delim)
{
	string joined = "";
	for (string& word : words)
		joined += word + delim;
	joined.erase(joined.length() - delim.length(), joined.length());
	// OR: joined = joined.substr(0, joined.length() - delim.length());
	return joined;
}

string JoinString(string words[], short length, string delim)
{
	string joined = "";
	for (short i = 0; i < length; i++)
		joined += words[i] + delim;
	joined.erase(joined.length() - delim.length(), joined.length());
	// OR: joined = joined.substr(0, joined.length() - delim.length());
	return joined;
}

int main()
{
	vector<string> vWords = { "Mohammed","Faid","Ali","Maher" };
	string arrWords[]     = { "Mohammed","Faid","Ali","Maher" };

	cout << "Vector after join: \n";
	cout << JoinString(vWords, "###") << endl;
	cout << "\nArray after join: \n";
	cout << JoinString(arrWords, 4, "###") << endl;

	return 0;
}
