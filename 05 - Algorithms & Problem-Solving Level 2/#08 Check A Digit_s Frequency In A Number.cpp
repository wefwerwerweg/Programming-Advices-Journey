// Problem: Count the Frequency of a Digit in a Number
// Coded By: @X99099

#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Count = 0, Remainder;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (DigitToCheck == Remainder)
            Count++;
    }
    return Count;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?");
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");
    
    cout << "\nDigit " << DigitToCheck << " Frequency is "
         << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";
    
    return 0;
}
