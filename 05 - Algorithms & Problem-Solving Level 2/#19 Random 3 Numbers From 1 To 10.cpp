// Problem: Generate Random Numbers Within a Range
// Coded By: @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int main() {
    srand((unsigned)time(NULL));
    
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
   
    return 0;
}
