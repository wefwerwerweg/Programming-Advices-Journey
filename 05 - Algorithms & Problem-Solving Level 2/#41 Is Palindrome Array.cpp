// Problem: Is Palindrome Array
// Coded By: @X99099

#include <iostream>
using namespace std;

bool isPalindromeArray(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        if (arr[i] != arr[length - i - 1])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {10, 10, 30, 40, 30, 10, 10}; 
    int length = 7;

    if (isPalindromeArray(arr, length))
        cout << "Yes, the array is a palindrome." << endl;
    else
        cout << "No, the array is not a palindrome." << endl;

    return 0;
}
