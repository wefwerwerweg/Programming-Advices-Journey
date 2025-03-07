// Problem: Print All From AAA to ZZZ
// Coded By: @X99099

#include <iostream>
using namespace std;

void printAllCombinations()
{
    string word;

    for (char i = 'A'; i <= 'Z'; i++) 
    {
        for (char j = 'A'; j <= 'Z'; j++) 
        {
            for (char k = 'A'; k <= 'Z'; k++) 
            {
                word = {i, j, k};  // Construct the word directly
                cout << word << endl;
            }
        }
        cout << "\n____________________________\n";  // Separate the groups for readability
    }
}

int main()
{
    printAllCombinations();
    return 0;
}
