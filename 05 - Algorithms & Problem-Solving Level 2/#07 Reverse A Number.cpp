// Problem: Reverse the Digits of a Positive Number
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

int ReverseNumber(int Number)
{
    int Remainder, Reversed = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Reversed = Reversed * 10 + Remainder;
    }
    return Reversed;
}

int main()
{
    cout << "\nReverse is:\n" 
         << ReverseNumber(ReadPositiveNumber("Please enter a positive number?"))
         << "\n";
    return 0;
}
