// Fill Array With Keys
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enumeration for character types
enum enCharType {
    SmallLetter = 1,        // Lowercase letters (ASCII range 97-122)
    CapitalLetter = 2,      // Uppercase letters (ASCII range 65-90)
    SpecialCharacter = 3,   // Special characters (ASCII range 33-47)
    Digit = 4               // Digits (ASCII range 48-57)
};

// Function to get a positive number from the user
int getPositiveNumber(const string& prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (number > 0) break;
        cout << "Please enter a positive number.\n";
    }
    return number;
}

// Function to generate a random number in a given range
int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Function to get a random character of a specific type
char getRandomCharacter(enCharType charType) {
    switch (charType) {
        case SmallLetter: return char(randomNumber('a', 'z'));
        case CapitalLetter: return char(randomNumber('A', 'Z'));
        case SpecialCharacter: return char(randomNumber(33, 47));
        case Digit: return char(randomNumber('0', '9'));
        default: return '\0'; // Return null character for invalid type
    }
}

// Function to generate a random 4-character key
string generateKey() {
    string key = "";
    for (int i = 0; i < 4; i++) {
        key += char(randomNumber('A', 'Z'));
    }
    return key;
}

// Function to fill an array with random keys
void fillKeysArray(string keys[], int size) {
    for (int i = 0; i < size; ++i) {
        keys[i] = generateKey();
    }
}

// Function to print an array of keys
void printKeysArray(const string keys[], int size, int index) {
    cout << "[" << index << "] Keys: ";
    for (int i = 0; i < size; i++) {
        cout << keys[i];
        if (i != size - 1) {
            cout << '-';
        }
    }
    cout << endl;
}

// Main function: Entry point of the program
int main() {
    srand((unsigned)time(NULL));

    // Get the number of arrays of keys to generate
    int count = getPositiveNumber("How many arrays of keys? ");

    const int keyCount = 4;
    string keys[keyCount];

    // Generate and print the keys arrays
    for (int i = 0; i < count; i++) {
        fillKeysArray(keys, keyCount);
        printKeysArray(keys, keyCount, i);
    }

    return 0;
}

// Problem: Fill Array With Keys
// Coded By: IcarusGhost
