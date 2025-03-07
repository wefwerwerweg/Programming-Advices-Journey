// Shuffle Array
// Coded By: @X99099

#include <iostream>
using namespace std;

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fillArrayWithRandomNumbers(int arr[100], int& length) {
    cout << "\nEnter number of elements:\n";
    cin >> length;
    for (int i = 0; i < length; i++) {
        arr[i] = generateRandom(1, 100);
    }
}

void printArray(const int arr[100], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void reverseArray(const int source[100], int dest[100], int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = source[length - 1 - i];
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arr2[100], length;

    fillArrayWithRandomNumbers(arr, length);
    reverseArray(arr, arr2, length);

    cout << "\nArray 1 elements:\n";
    printArray(arr, length);

    cout << "\nArray 2 elements after copy:\n";
    printArray(arr2, length);

    return 0;
}
