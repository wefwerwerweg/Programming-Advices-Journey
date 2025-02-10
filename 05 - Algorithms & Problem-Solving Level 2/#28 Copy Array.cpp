// Copy Array
// https://programmingadvices.com/courses/1811531/lectures/41372866/comments/25782471

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void AddElements(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void CopyArray(int arr1[], int arr2[], int length)
{
	for (int i = 0; i < length; i++)
		arr2[i] = arr1[i];
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], length;
	cout << "Array Length: ";
	cin >> length;

	AddElements(arr1, length);
	CopyArray(arr1, arr2, length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, length);
	cout << "\nArray 2 Elements After Copy:\n";
	PrintArray(arr2, length);
}