// Problem: MyFloor Function
// Coded By: @X99099

#include <iostream>
#include <cmath>  
using namespace std;

float getNumber(string message) {
    float number = 0;

    cout << message;
    cin >> number;

    return number;
}

int myFloor(float number) {
    int intPart = (int)number;

    if (intPart < 0) intPart--;

    return intPart;
}


int main() {
    float number = getNumber("Please Enter a Number: ");
    cout << "\n";

    cout << "My Floor Result : " << myFloor(number) << endl;
    cout << "C++ Floor Result: " << floor(number) << endl;

    return 0;
}
