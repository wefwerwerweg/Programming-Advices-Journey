// Average Of Random Array
// Coded By: @X99099

#include <iostream>
using namespace std;

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArray(int arr[100], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int SumArray(int arr[100], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += arr[i];
    return sum;
}

float Average(int arr[100], int length)
{
    return (float)SumArray(arr, length) / length;
}

int main() {
    srand((unsigned)time(0));
    
    int arr[100], length;
    FillArray(arr, length);
    
    if (length <= 0 || length > 100)
        return 0;

    PrintArray(arr, length);
    
    cout << "\nAverage: " << Average(arr, length) << endl;

    return 0;
}h)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return (float) sum / length;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], length;
	cout << "Array Length: ";
	cin >> length;
	AddElements(arr, length);
	PrintArray(arr, length);
	cout << "Average Of All Numbers Is: " << Average(arr, length) << endl;
}
