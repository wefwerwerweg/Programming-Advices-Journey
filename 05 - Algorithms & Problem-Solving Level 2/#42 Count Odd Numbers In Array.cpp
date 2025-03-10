// Problem: Count Odd Numbers In Array
// Coded By: @X99099 

#include <iostream>
using namespace std;

int getNumber(string message)
{
    int number = 0;

    cout << message;
    cin >> number;

    return number;
}

void fillArray(int arr[], int max)
{
    for (int i = 0; i < 100; i++) {
        arr[i] = generateNumber(0, max);
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++) {

        cout << arr[i] << ", ";

    }

    cout << endl;
}

bool CountOddNumsInArray(int arr[], int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 2) count++;
    }

    return count;
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int length = getNumber("Please Enter Array Length: ");    

    fillArray(arr, length);
    printArray(arr, length);

    cout << "Odd Numbers In The Array Is " << CountOddNumsInArray(arr, length) << endl;

    return 0;
}
