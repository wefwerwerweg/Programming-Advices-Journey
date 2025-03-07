// Problem: Print Inverted Letter Pattern
// Coded By: @X99099

#include <iostream>
using namespace std;

int getPositiveNumber(string msg)
{
    int num = 0;
    do
    {
        cout << msg << endl;
        cin >> num;
    } while (num <= 0);
    return num;
}

void printInvertedLetterPattern(int num)
{
    cout << "\n";

    for (int i = 65 + num - 1; i >= 65; i--)
    {
        for (int j = 1; j <= num - ((65 + num - 1) - i); j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    printInvertedLetterPattern(getPositiveNumber("Please enter a positive number?"));
    return 0;
}
