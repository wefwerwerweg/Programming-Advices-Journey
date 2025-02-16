// #27 Invert Character Case
// https://programmingadvices.com/courses/1869980/lectures/42654926/comments/25844039

#include <iostream>
#include <cctype>

using namespace std;

char InvertCharacterCase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

int main()
{
	char c;
	cout << "Please enter a character:\n";
	cin >> c;
	cout << "\nCharacter after inverting case:\n";
	cout << InvertCharacterCase(c) << endl;
	return 0;
}
