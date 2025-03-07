// Problem: Check if a Number is Perfect
// Coded By: @X99099

#include <iostream>
#include <string>
using namespace std;

int GetPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    
    return Number;
}

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    
    return Number == Sum;
}

void DisplayResults(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " is a perfect number.\n";
    else
        cout << Number << " is not a perfect number.\n";
}

int main()
{
    DisplayResults(GetPositiveNumber("Enter a positive number: "));
    return 0;
}
