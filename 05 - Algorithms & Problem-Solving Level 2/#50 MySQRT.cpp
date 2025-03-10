// Problem: MySqrt Function
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

float mySqrt(float number) {
    return pow(number, 0.5);  
}

int main() {
    float number = getNumber("Please Enter a Number: ");
    cout << "\n";

    cout << "My Sqrt Result : " << mySqrt(number) << endl;
    cout << "C++ Sqrt Result: " << sqrt(number) << endl;

    return 0;
}
