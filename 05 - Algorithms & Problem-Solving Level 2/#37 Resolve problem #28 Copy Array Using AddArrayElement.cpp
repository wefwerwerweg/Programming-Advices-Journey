#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Problem: Copy Array Elements Using AddArrayElement
    Coded By: @X99099
*/

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

// Function to fill an array with random numbers between 1 and 99
void fillArray(int array[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        array[i] = randomNumber(1, 99);
    }
}

// Function to add a number to the array and track its position
void addArrayElement(int arr[], int& arrLength, int number) {
    arr[arrLength++] = number;
}

// Function to copy elements from one array to another
void copyArray(int arr1[], int arr2[], int arrLength, int& arr2Length) {
    for (int i = 0; i < arrLength; i++) {
        addArrayElement(arr2, arr2Length, arr1[i]);
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

    copyArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    printArray(arr, arrLength);

    cout << "\nArray 2 elements after copy:\n";
    printArray(arr2, arr2Length);

    return 0;
}
