// Problem: Add Elements To Array Semi Dynamic
// Coded By: @X99099

#include <iostream>
using namespace std;

int getNumber(const string& prompt) {
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

void addToArr(int arr[100], int& size, int num) {
    arr[size++] = num;
}

void inputNumbers(int arr[100], int& size) {
    bool add = true;
    do {
        addToArr(arr, size, getNumber("Please Enter a Number: "));
        add = getNumber("Do You Want To Add More Numbers [1]YES [0]NO: ");
    } while (add);
}

void printArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int arrLength = 0;

    inputNumbers(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    printArr(arr, arrLength);

    return 0;
}
