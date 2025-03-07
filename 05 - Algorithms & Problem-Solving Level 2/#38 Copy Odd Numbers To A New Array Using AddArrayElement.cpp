#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
    Problem: Copy Odd Numbers To A New Array Using AddArrayElement
    Coded By: @X99099
*/

// Function to generate a random number in a given range
int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Function to check if a number is odd
bool isOdd(int number) {
    return number % 2 != 0;
}

// Function to print the contents of an array
void printArray(const int array[], int arrLength, const string& message) {
    cout << message;
    for (int i = 0; i < arrLength; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to fill an array with random numbers between 1 and 99
void fillArray(int array[], int& arrLength) {
    for (int i = 0; i < arrLength; i++) {
        array[i] = randomNumber(1, 99);
    }
}

// Function to add a number to an array and increase its size
void addArrayElement(int arr[], int& arrLength, int number) {
    arr[arrLength++] = number;
}

// Function to copy only odd numbers from one array to another
void copyOddNumbers(int source[], int destination[], int sourceLength, int& destinationLength) {
    for (int i = 0; i < sourceLength; i++) {
        if (isOdd(source[i])) {
            addArrayElement(destination, destinationLength, source[i]);
        }
    }
}

// Main function: Program entry point.
int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 10;

    fillArray(arr, arrLength);

    int arr2[100];
    int arr2Length = 0;

    copyOddNumbers(arr, arr2, arrLength, arr2Length);

    printArray(arr, arrLength, "\nOriginal Array:\n");
    printArray(arr2, arr2Length, "\nOdd Numbers Array:\n");

    return 0;
}
