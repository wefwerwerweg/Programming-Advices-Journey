// #33 Count Vowels
// https://programmingadvices.com/courses/1869980/lectures/42662796/comments/25844919

#include <iostream>
#include <string>

using namespace std;

bool IsVowel(char c)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u'};
	for (char vowel : vowels)
		if (tolower(c) == vowel) return true;
	return false;
}

short CountVowels(string text)
{
	short count = 0;
	for (char c : text)
		if (IsVowel(c)) count++;
	return count;
}

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nVowels count is: " << CountVowels(text) << endl;

	return 0;
}
