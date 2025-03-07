// Problem: Generate Random Keys
// Coded By: @X99099

#include <iostream>
using namespace std;

enum enCharType { 
    SmallLetter = 1,    
    CapitalLetter = 2,   
    SpecialCharacter = 3,
    Digit = 4            
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
            return char(RandomNumber('a', 'z'));
        case enCharType::CapitalLetter:
            return char(RandomNumber('a', 'z'));
        case enCharType::SpecialCharacter:
            return char(RandomNumber('a', 'z'));
        case enCharType::Digit:
            return char(RandomNumber('a', 'z'));
    }
    return '\0';
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n\n";
    for (int i = 0; i < arrLength; i++)
        cout << "Array[" << i << "] : " << arr[i] << "\n";
    cout << "\n";
}

string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
        Word += GetRandomCharacter(CharType);
    return Word;
}

string GenerateKey()
{
    string Key = "";
    for (int i = 0; i < 3; i++)
    {
        Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    }
    Key += GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}

void FillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int main() {
    srand((unsigned)time(NULL));
    
    string arr[100];
    int arrLength = ReadPositiveNumber("How many keys do you want to generate?\n");
    
    FillArrayWithKeys(arr, arrLength);
    
    PrintStringArray(arr, arrLength);
    
    return 0;
}
