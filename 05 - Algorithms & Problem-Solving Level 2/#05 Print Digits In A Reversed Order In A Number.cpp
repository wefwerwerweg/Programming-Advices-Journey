// Problem: Print Digits of a Number in Reverse Order
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

void PrintDigits(int Number)
{
    while (Number > 0)
    {
        cout << Number % 10 << endl;
        Number /= 10;
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("Please enter a positive number:"));
    return 0;
}
