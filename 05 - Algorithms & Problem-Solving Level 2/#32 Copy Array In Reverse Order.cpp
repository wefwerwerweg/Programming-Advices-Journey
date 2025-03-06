// Copy Array In Reverse Order

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

// Function to generate a random number in the specified range [from, to]
int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Function to fill an array with random numbers in the range [1, 99]
void fillArrayWithRandomNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomNumber(1, 99);
    }
}

// Function to print the contents of an array
void printArray(const int array[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to reverse the elements of an array
void reverseArray(const int original[], int reversed[], int size) {
    for (int i = 0; i < size; i++) {
        reversed[i] = original[size - i - 1];
    }
}

// Main function: Entry point of the program
int main() {
    srand((unsigned)time(NULL));

    // Declare arrays to store original and reversed arrays
    int arr[100], reversedArr[100];

    // Get the number of elements from the user
    int arrLength = getPositiveNumber("How many elements? ");

    // Fill the array with random numbers
    fillArrayWithRandomNumbers(arr, arrLength);

    // Reverse the array
    reverseArray(arr, reversedArr, arrLength);

    // Print the original array
    cout << "Original Array:\n";
    printArray(arr, arrLength);

    // Print the reversed array
    cout << "\nArray After Reverse:\n";
    printArray(reversedArr, arrLength);

    return 0;
}

// Coded By IcarusGhost
