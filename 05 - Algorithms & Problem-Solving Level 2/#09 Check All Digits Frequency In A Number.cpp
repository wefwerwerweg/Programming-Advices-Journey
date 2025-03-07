// Check All Digits Frequency In A Number
// Coded By: @X99099

#include <iostream>
using namespace std;

int getPositiveNumber(const string& prompt) {
    int num;
    do {
        cout << prompt << endl;
        cin >> num;
    } while (num <= 0);
    
    return num;
}

int getDigitCount(short digit, int num) {
    int count = 0;
    while (num) {
        if (num % 10 == digit) 
            count++;
        num /= 10;
    }
    return count;
}

void displayDigitCounts(int num) {
    cout << endl;
    for (int i = 0; i < 10; i++) {
        int count = getDigitCount(i, num);
        if (count) 
            cout << "Digit " << i << " occurs " << count << " time(s).\n";
    }
}

int main() {
    int num = getPositiveNumber("Enter a positive number:");
    displayDigitCounts(num);
    
    return 0;
}
