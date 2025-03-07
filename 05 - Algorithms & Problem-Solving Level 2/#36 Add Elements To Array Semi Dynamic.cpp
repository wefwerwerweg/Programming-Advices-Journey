/*
    Problem: Add Elements To Array Semi Dynamic
    Coded By: @X99099
*/

#include <iostream>
using namespace std;

// Function to get a number from the user
int getNumber(const string& prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}

// Function to add a number to the array and track its position
void addNumberToArray(int arr[100], int& size, int number) {
    arr[size] = number;
    size++;
}

// Function to handle user input for adding numbers to the array
void inputUserNumbersInArray(int arr[100], int& size) {
    bool add = true;
    do {
        addNumberToArray(arr, size, getNumber("Please Enter a Number: "));
        add = getNumber("Do You Want To Add More Numbers [1]YES [0]NO: ");
    } while (add);
}

// Function to print the contents of an array
void printArray(const int array[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Main function: Program entry point
int main() {
    int arr[100];      
    int arrLength = 0; 

    // Prompt the user to input numbers into the array
    inputUserNumbersInArray(arr, arrLength);

    // Print the final array length and its elements
    cout << "\nArray Length: " << arrLength << endl;
    printArray(arr, arrLength);

    return 0; 
