// Sum Of 2 Arrays To A 3rd Array
// https://programmingadvices.com/courses/1811531/lectures/41372962/comments/25782676

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

void SumArrays(int arr1[], int arr2[], int arrSum[], int length)
{
	for (int i = 0; i < length; i++)
		arrSum[i] = arr1[i] + arr2[i];
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
	int arr1[100], arr2[100], arrSum[100], length;

	cout << "Array Length: ";
	cin >> length;

	AddElements(arr1, length);
	AddElements(arr2, length);
	SumArrays(arr1, arr2, arrSum, length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, length);
	cout << "\nArray 2 Elements:\n";
	PrintArray(arr2, length);
	cout << "\nSum Of Array 1 And 2:\n";
	PrintArray(arrSum, length);
}