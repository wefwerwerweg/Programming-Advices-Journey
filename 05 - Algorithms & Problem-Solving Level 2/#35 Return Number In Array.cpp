// Problem: Return Number In Array
// Coded By: @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int getPositiveNumber(const string& prompt) {
    int num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (num > 0) break;
        cout << "Please enter a positive number.\n";
    }
    return num;
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = randomNumber(1, 99);
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool searchNumber(int arr[], int num, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) return true;
    }
    return false;
}

int main() {
    srand(time(0));

    int arr[100];
    int arrLength = getPositiveNumber("How many elements: ");
    fillArray(arr, arrLength);
    printArray(arr, arrLength);

    int num = getPositiveNumber("Enter a Number To Search For: ");
    if (searchNumber(arr, num, arrLength)) {
        cout << "Yes, The Number Is Found :-)" << endl;
    } else {
        cout << "No, The Number Isn't Found :-(" << endl;
    }

    return 0;
}
