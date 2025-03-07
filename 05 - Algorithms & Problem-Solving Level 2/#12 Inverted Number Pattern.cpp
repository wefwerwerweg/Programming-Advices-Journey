// Problem: Print Inverted Number Pattern
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

void printInvertedPattern(int num) {
    for (int i = num; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {
    int num = getPositiveNumber("Enter a positive number:");
    printInvertedPattern(num);
    
    return 0;
}
