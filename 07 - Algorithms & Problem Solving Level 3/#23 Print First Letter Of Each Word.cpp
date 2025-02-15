// #23 Print First Letter Of Each Word
// https://programmingadvices.com/courses/1869980/lectures/42568549/comments/25840150

#include <iostream>
#include <string>

using namespace std;

void PrintFirstLetterOfEachWord(string text)
{
	if (text[0] != ' ') cout << text[0] << endl;

	int findPos = text.find(' ');
	while (findPos != text.npos)
	{
		if (findPos + 1 != text.length())
			if (text[findPos + 1] != ' ')
				cout << text[findPos + 1] << endl;
		text = text.substr(findPos + 1);
		findPos = text.find(' ');
	}
}

int main()
{
	string text;
	cout << "Please Enter Your String:\n";
	getline(cin, text);
	cout << "\nFirst Letter Of Each Word:\n";
	PrintFirstLetterOfEachWord(text);
	return 0;
}
