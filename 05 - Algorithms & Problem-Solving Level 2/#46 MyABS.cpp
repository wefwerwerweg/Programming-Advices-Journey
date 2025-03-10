// Problem: MyABS Function
// Coded By: @X99099 

#include <iostream>
#include <cstdlib>
using namespace std;

int getNumber(string message)
{
    int number = 0;

    cout << message;
    cin >> number;

    return number;
}

int myABS(int number) {
    if (number >= 0)
        return number;
    return -number; 
}

int main() {
    int number = getNumber("Please Enter a Number: ");    
    cout << "\n";

    cout << "My ABS Result : " << myABS(number) << endl;
    cout << "C++ ABS Result: " << abs(number);
    return 0;
}
