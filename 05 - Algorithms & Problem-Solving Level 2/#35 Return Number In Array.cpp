// Coded By @X99099
// Problem #34: Return Number In Array

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number in a given range
int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;  // Generate a random number between 'from' and 'to'
}

// Function to get a positive number from the user
int getPositiveNumber(const string& prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (number > 0) break;  // Ensure the number is positive
        cout << "Please enter a positive number.\n";
    }
    return number;
}

// Function to fill an array with random numbers between 1 and 99
void fillArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = randomNumber(1, 99);  // Fill the array with random numbers between 1 and 99
    }
}

// Function to print the contents of an array
void printArray(const int array[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";  // Print each element
    }
    cout << endl;
}

// Function to search for a number in the array
bool arraySearch(int array[], int number, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;  // Return true if the number is found
        }
    }
    return false;  // Return false if the number is not found
}

// Main function: Entry point of the program
int main() {
    srand((unsigned)time(NULL));  // Seed the random number generator

    int arr[100];  // Declare an array to hold up to 100 elements

    // Get the number of elements from the user
    int arrLength = getPositiveNumber("How many elements: ");

    // Fill the array with random numbers and print the array
    fillArray(arr, arrLength);
    printArray(arr, arrLength);
    
    // Get the number to search for from the user
    int number = getPositiveNumber("Enter a Number To Search For: ");

    // Perform the search and print the result
    if (arraySearch(arr, number, arrLength)) {
        cout << "Yes, The Number Is Found :-)" << endl;
    } else {
        cout << "No, The Number Isn't Found :-(" << endl;
    }

    return 0;
}
