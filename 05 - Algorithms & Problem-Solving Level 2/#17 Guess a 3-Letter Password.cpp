// Problem: Guess a 3-Letter Password by Brute Force
// Coded By: @X99099

#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
    string password;
    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> password;
    return password;
}

bool GuessPassword(string originalPassword)
{
    string word;
    int counter = 0;
    
    for (char i = 'A'; i <= 'Z'; i++) 
    {
        for (char j = 'A'; j <= 'Z'; j++) 
        {
            for (char k = 'A'; k <= 'Z'; k++) 
            {
                word = {i, j, k};  // Directly build the string with characters
                counter++;

                cout << "Trial [" << counter << "] : " << word << endl;

                if (word == originalPassword)
                {
                    cout << "\nPassword is " << word << "\n";
                    cout << "Found after " << counter << " Trial(s)\n";
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    GuessPassword(ReadPassword());
    return 0;
}
