// Problem: Print Prime Numbers Up to N
// Coded By: @X99099

#include <iostream>
#include <string>
using namespace std;

enum PrimeStatus { Prime = 1, NotPrime = 2 };

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

PrimeStatus IsPrime(int Number)
{
    for (int i = 2; i <= Number / 2; i++)
    {
        if (Number % i == 0)
            return NotPrime;
    }
    
    return Prime;
}

void DisplayPrimes(int Number)
{
    cout << "\nPrime Numbers up to " << Number << " are:\n";
    
    for (int i = 1; i <= Number; i++)
    {
        if (IsPrime(i) == Prime)
            cout << i << endl;
    }
}

int main()
{
    DisplayPrimes(GetPositiveNumber("Enter a positive number: "));
    return 0;
}
