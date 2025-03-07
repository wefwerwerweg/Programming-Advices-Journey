// Problem: Sum of Digits of a Positive Number
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

int SumOfDigits(int Number)
{
    int Sum = 0;
    while (Number > 0)
    {
        Sum += Number % 10;
        Number /= 10;
    }
    return Sum;
}

int main()
{
    cout << "\nSum Of Digits = " 
         << SumOfDigits(ReadPositiveNumber("Please enter a positive number?"))
         << "\n";
    return 0;
}
