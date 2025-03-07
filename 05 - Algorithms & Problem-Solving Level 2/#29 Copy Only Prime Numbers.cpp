// Problem: Copy Only Prime Numbers from One Array to Another
// Coded By: @X99099

#include <iostream>
using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int num) {
    if (num < 2) return enPrimNotPrime::NotPrime;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}

int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FillArray(int arr[100], int &size) {
    cout << "Enter number of elements: ";
    cin >> size;
    for (int i = 0; i < size; i++) 
        arr[i] = RandomNumber(1, 100);
}

void CopyPrimes(int src[100], int dest[100], int size, int &destSize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (CheckPrime(src[i]) == enPrimNotPrime::Prime) {
            dest[count++] = src[i];
        }
    }
    destSize = count;
}

void PrintArray(int arr[100], int size) {
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArray(arr, arrLength);

    int arr2[100], arr2Length;
    CopyPrimes(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 (random numbers): ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 (prime numbers): ";
    PrintArray(arr2, arr2Length);

    return 0;
}
