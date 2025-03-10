// Problem: MyCeil Function
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

int myCeil(float number) {
    int intPart = (int)number; 

    if (number > intPart) intPart++;
    
    return intPart;
}


int main() {
    float number = getNumber("Please Enter a Number: ");
    cout << "\n";

    cout << "My Floor Result : " << myCeil(number) << endl;
    cout << "C++ Floor Result: " << ceil(number) << endl;

    return 0;
}
