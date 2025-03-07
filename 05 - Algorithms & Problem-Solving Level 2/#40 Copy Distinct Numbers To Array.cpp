// Problem: Copy Distinct Numbers To Array
// Coded By: @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number in a given range
int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Function to print the contents of an array
void printArray(const int array[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to fill an array with random numbers in a given range
void fillArray(int array[], int arrLength, int from = 1, int to = 99) {
    for (int i = 0; i < arrLength; i++) {
        array[i] = randomNumber(from, to);
    }
}

// Function to add a number to the array and update its length
void addArrayElement(int arr[], int& arrLength, int number) {
    arr[arrLength++] = number;
}

// Function to search for a number in the array
bool arraySearch(const int array[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return true;  // Number found
        }
    }
    return false;  // Number not found
}

// Function to copy unique elements from one array to another
void copyUniqueElements(const int source[], int destination[], int sourceLength, int& destinationLength) {
    for (int i = 0; i < sourceLength; i++) {
        if (!arraySearch(destination, destinationLength, source[i])) {
            addArrayElement(destination, destinationLength, source[i]);
        }
    }
}

// Main function: Program entry point
int main() {
    srand((unsigned)time(NULL));

    int arr[] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };
    int arrLength = 10;

    int uniqueArr[100];
    int uniqueArrLength = 0;

    copyUniqueElements(arr, uniqueArr, arrLength, uniqueArrLength);

    cout << "\nOriginal Array:\n";
    printArray(arr, arrLength);

    cout << "\nUnique Elements Array:\n";
    printArray(uniqueArr, uniqueArrLength);

    return 0;
}
