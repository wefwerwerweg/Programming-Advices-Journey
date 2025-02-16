// #32 Is Vowel
// https://programmingadvices.com/courses/1869980/lectures/42662581/comments/25844871

#include <iostream>

using namespace std;

bool IsVowel(char c)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u'};
	for (char vowel : vowels)
		if (tolower(c) == vowel) return true;
	return false;
}

int main()
{
	char c;
	cout << "Please enter a character: ";
	cin >> c;

	if (IsVowel(c))
		cout << "\nYES: Letter '" << c << "' is vowel\n";
	else
		cout << "\nNO: Letter '" << c << "' is NOT vowel\n";

	return 0;
}
