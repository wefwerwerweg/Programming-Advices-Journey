// Sum Of Random Array
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

int SumArray(int arr[100], int arrLength) {
    int sum = 0;

    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nSum of all numbers is: " << SumArray(arr, arrLength) << endl;

    return 0;
}
