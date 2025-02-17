// #39 Join String
// https://programmingadvices.com/courses/1869980/lectures/42697524/comments/25851348

#include <iostream>
#include <vector>

using namespace std;

string JoinString(vector<string>& words, string delim)
{
	string joined = "";
	for (string& word : words)
		joined += word + delim;
	joined.erase(joined.length() - delim.length(), joined.length());
	return joined;
}

int main()
{
	vector<string> words = { "Mohammed","Faid","Ali","Maher" };
	cout << "Vector after join: \n";
	cout << JoinString(words, "$$") << endl;
	return 0;
}

/*Instructor Solution:
string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
*/
