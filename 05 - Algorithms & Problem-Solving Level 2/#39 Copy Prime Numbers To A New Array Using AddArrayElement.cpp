// Problem: Copy Prime Numbers To A New Array Using AddArrayElement
// Coded By: @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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

// Function to check if a number is prime
bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    int sqrtX = sqrt(x);
    for (int i = 5; i <= sqrtX; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }

    return true;
}

// Function to copy only prime numbers from one array to another
void copyPrimeNumbers(const int source[], int destination[], int sourceLength, int& destinationLength) {
    for (int i = 0; i < sourceLength; i++) {
        if (isPrime(source[i])) {
            addArrayElement(destination, destinationLength, source[i]);
        }
    }
}

// Main function: Program entry point
int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 10;

    fillArray(arr, arrLength);

    int primeArr[100];
    int primeArrLength = 0;

    copyPrimeNumbers(arr, primeArr, arrLength, primeArrLength);

    cout << "\nOriginal Array Elements:\n";
    printArray(arr, arrLength);

    cout << "\nPrime Numbers Array:\n";
    printArray(primeArr, primeArrLength);

    return 0;
}
