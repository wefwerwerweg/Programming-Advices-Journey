// Problem: MyRound Function
// Coded By: X99099

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

int myRound(float number) {
    float decimalPart = getDecimalPart(number);
    int inPart = (int)number;

    if (abs(decimalPart) >= 0.5) {
        if (number > 0) {
            inPart++;
        }
        else {
            inPart--;
        }
    }

    return inPart;
}

int main() {
    float number = getNumber("Please Enter a Number: ");
    cout << "\n";

    cout << "My Round Result : " << myRound(number) << endl;
    cout << "C++ Round Result: " << round(number) << endl; 

    return 0;
}
