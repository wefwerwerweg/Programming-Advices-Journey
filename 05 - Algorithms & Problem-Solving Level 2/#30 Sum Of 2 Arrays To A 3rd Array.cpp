// Problem: Sum of Two Arrays
// Coded By: @X99099

#include <iostream>
using namespace std;

int generateRandom(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int getPositiveNumber(string prompt) {
    int number;
    do {
        cout << prompt;
        cin >> number;
    } while (number <= 0);
    
    return number;
}

void fillRandomNumbers(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = generateRandom(1, 100);
    }
}

void addArrays(int arr1[], int arr2[], int result[], int length) {
    for (int i = 0; i < length; i++) {
        result[i] = arr1[i] + arr2[i];
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrSum[100];
    
    int length = getPositiveNumber("Enter number of elements: ");

    fillRandomNumbers(arr, length);
    fillRandomNumbers(arr2, length);

    addArrays(arr, arr2, arrSum, length);

    cout << "\nArray 1:\n";
    printArray(arr, length);

    cout << "\nArray 2:\n";
    printArray(arr2, length);

    cout << "\nSum of arrays:\n";
    printArray(arrSum, length);

    return 0;
}
