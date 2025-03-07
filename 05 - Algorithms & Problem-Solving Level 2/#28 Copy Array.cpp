// Copy Array
// Coded By: @X99099

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArray(int arr[MAX_SIZE], int &size) {
    cout << "Enter number of elements (1 to " << MAX_SIZE << "): ";
    cin >> size;
    if (size < 1 || size > MAX_SIZE) return;
    for (int i = 0; i < size; i++) 
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void CopyArray(int src[MAX_SIZE], int dest[MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) 
        dest[i] = src[i];
}

int main() {
    srand((unsigned)time(NULL));
    
    int arr[MAX_SIZE], arrLength;
    FillArray(arr, arrLength);
    
    if (arrLength <= 0 || arrLength > MAX_SIZE) return 0;

    int arrCopy[MAX_SIZE];
    CopyArray(arr, arrCopy, arrLength);

    cout << "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 elements after copy: ";
    PrintArray(arrCopy, arrLength);

    return 0;
}
