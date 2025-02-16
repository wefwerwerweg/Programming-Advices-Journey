// #34 Print All Vowels In String
// https://programmingadvices.com/courses/1869980/lectures/42662908/comments/25844938

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

void PrintVowels(string text)
{
	for (char c : text)
		if (IsVowel(c)) cout << c << "   ";
}

int main()
{
	string text;
	cout << "Please enter a string:\n";
	getline(cin, text);
	cout << "\nVowels in string: ";
	PrintVowels(text);
	cout << endl;
	return 0;
}
