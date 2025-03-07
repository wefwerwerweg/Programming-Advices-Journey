// Problem: Print Letter Pattern
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

void printLetterPattern(int num)
{
    cout << "\n";

    for (int i = 65; i < 65 + num; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    printLetterPattern(getPositiveNumber("Please enter a positive number?"));
    return 0;
}
