// Problem #34: Return Number Index In Array
// Coded By @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getPositiveNumber(const string& prompt)
{
    int number;
    do {
        cout << prompt;
        cin >> number;
    } while (number <= 0);  // Ensure the number is positive
    return number;
}

int randomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void printArray(const int array[], int size)
{
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void fillArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = randomNumber(1, 99);  // Random numbers between 1 and 99
    }
}

void arraySearch(int array[], int number, int size)
{
    cout << "\nThe Number You're Looking For: " << number << endl;

    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            cout << "The Number Found At Position: " << i << "\n";
            cout << "The Number Found In Order: " << i + 1 << "\n"; // Human-friendly format
            return;
        }
    }

    cout << "The Number Isn't Found :-(" << endl;  // If the number is not found
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    int arr[100];
    int arrLength = getPositiveNumber("How many elements: ");  // Get the array size from user

    fillArray(arr, arrLength);  // Fill the array with random values
    printArray(arr, arrLength);  // Print the array
    
    int number = getPositiveNumber("Enter a Number To Search For: ");  // Get the number to search for
    arraySearch(arr, number, arrLength);  // Search and display the result

    return 0;
}
