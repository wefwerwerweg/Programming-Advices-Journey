// Print All Digits In Order In A Number
// Coded By: @X99099

#include <iostream>
#include <string>
using namespace std;

int getPositiveNumber(const string& prompt) {
    int num;
    do {
        cout << prompt << endl;
        cin >> num;
    } while (num <= 0);
    
    return num;
}

int reverseNumber(int num) {
    int remainder = 0, reversed = 0;
    
    while (num > 0) {
        remainder = num % 10;
        num /= 10;
        reversed = reversed * 10 + remainder;
    }
    
    return reversed;
}

void printDigits(int num) {
    while (num > 0) {
        cout << num % 10 << endl;
        num /= 10;
    }
}

int main() {
    int num = getPositiveNumber("Enter a positive number:");
    printDigits(reverseNumber(num));
    
    return 0;
}
