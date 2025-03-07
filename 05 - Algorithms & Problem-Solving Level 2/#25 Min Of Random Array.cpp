// Min Of Random Array
// Coded By: @X99099

#include <iostream>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength) {
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int MinNumberInArray(int arr[100], int arrLength) {
    int Min = arr[0];

    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < Min) Min = arr[i];
    }

    return Min;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nMin Number is: " << MinNumberInArray(arr, arrLength) << endl;

    return 0;
}
