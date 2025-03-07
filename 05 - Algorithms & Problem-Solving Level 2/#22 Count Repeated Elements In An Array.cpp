// Problem: Count Frequency of a Number in an Array
// Coded By: @X99099

#include <iostream>
using namespace std;

int ReadPositiveNumber(string msg)
{
    int num = 0;
    do
    {
        cout << msg << endl;
        cin >> num;
    } while (num <= 0);
    
    return num;
}

void ReadArray(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int TimesRepeated(int num, int arr[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (num == arr[i])
            count++;
    }
    return count;
}

int main() 
{
    int arr[100], arrLength, numberToCheck;

    ReadArray(arr, arrLength);
    numberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);

    cout << "\nNumber " << numberToCheck << " is repeated ";
    cout << TimesRepeated(numberToCheck, arr, arrLength) << " time(s)\n";

    return 0;
}
