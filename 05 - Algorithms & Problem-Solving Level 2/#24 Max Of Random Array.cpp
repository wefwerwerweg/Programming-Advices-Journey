// Max Of Random Array
// Coded By: @X99099

#include <iostream>
using namespace std;

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int MaxNumberInArray(int arr[100], int arrLength)
{
    int max = 0;
    
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nMax Number is : ";
    cout << MaxNumberInArray(arr, arrLength) << endl;

    return 0;
}
