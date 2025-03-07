// Check For Palindrome Number
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

bool isPalindrome(int num) {
    return num == reverseNumber(num);
}

int main() {
    int num = getPositiveNumber("Enter a positive number:");
    if (isPalindrome(num))
        cout << "\nYes, it is a Palindrome number.\n";
    else
        cout << "\nNo, it is NOT a Palindrome number.\n";
    
    return 0;
}
