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

int getDecimalPart(float number) {
    return (number - (int)number) * 10;
}

int myFloor(float number) {
    float decimalPart = getDecimalPart(number);
    int inPart = (int)number;

    if (decimalPart >= -5 && number < 0) inPart--;

    return inPart;
}

int main() {
    float number = getNumber("Please Enter a Number: ");
    cout << "\n";

    cout << "My Floor Result : " << myFloor(number) << endl;
    cout << "C++ Floor Result: " << floor(number) << endl;

    return 0;
}
