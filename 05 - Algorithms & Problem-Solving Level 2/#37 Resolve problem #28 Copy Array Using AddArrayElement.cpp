// Problem: Copy Array Elements Using AddArrayElement
// Coded By: @X99099

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void printArr(const int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = randomNum(1, 99);
    }
}

void addElement(int arr[], int& length, int num) {
    arr[length++] = num;
}

void copyArr(int arr1[], int arr2[], int length, int& length2) {
    for (int i = 0; i < length; i++) {
        addElement(arr2, length2, arr1[i]);
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int length = 10;

    fillArr(arr, length);

    int arr2[100];
    int length2 = 0;

    copyArr(arr, arr2, length, length2);

    cout << "\nArray 1 elements:\n";
    printArr(arr, length);

    cout << "\nArray 2 elements after copy:\n";
    printArr(arr2, length2);

    return 0;
}
