// Copy Array In Reverse Order
// https://programmingadvices.com/courses/1811531/lectures/41411122/comments/25786255
// https://programmingadvices.com/courses/1811531/lectures/41411122/comments/25786344

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

void ReverseCopyArray(int arr1[], int arr2[], int length)
{
	for (int i = 0; i < length; i++)
		arr2[i] = arr1[length - i - 1];
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], length;
	cout << "Number Of Elements: ";
	cin >> length;

	AddElements(arr1, length);
	ReverseCopyArray(arr1, arr2, length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, length);
	cout << "\nArray 2 Elements After Reverse Copy:\n";
	PrintArray(arr2, length);
}