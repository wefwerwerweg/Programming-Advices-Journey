// Keys Generator.
// Coded By: @X99099

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {
        case SmallLetter: return char(RandomNumber('a', 'z'));
        case CapitalLetter: return char(RandomNumber('A', 'Z'));
        case SpecialCharacter: return char(RandomNumber(33, 47));
        case Digit: return char(RandomNumber('0', '9'));
    }
    return '\0';
}

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

string GenerateWord(enCharType CharType, short Length) {
    string Word;
    for (int i = 1; i <= Length; i++) {
        Word += GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey() {
    return GenerateWord(CapitalLetter, 4) + "-" + GenerateWord(CapitalLetter, 4) + "-" + GenerateWord(CapitalLetter, 4) + "-" + GenerateWord(CapitalLetter, 4);
}

void GenerateKeys(short NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++) {
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate: "));
    return 0;
};

	int n;
	cout << "Number Of Keys To Generate: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey() << endl;
	}
}
