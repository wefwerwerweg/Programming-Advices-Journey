// Copy Odd Numbers To A New Array Using AddArrayElement
// https://programmingadvices.com/courses/1811531/lectures/41414414/comments/25786968

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void AddElements(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = RandomNumber(1, 100);
}

void AddArrayElement(int num, int arr[], int& length)
{
	arr[length++] = num;
}

void CopyArray(int arr1[], int arr2[], int arr1Length, int& arr2Length)
{
	for (int i = 0; i < arr1Length; i++)
		if (arr1[i] % 2) AddArrayElement(arr1[i], arr2, arr2Length);
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main()
{
	srand((unsigned) time(NULL));
	int arr1[100], arr2[100], arr1Length, arr2Length = 0;
	cout << "Number Of Elements: ";
	cin >> arr1Length;
	AddElements(arr1, arr1Length);
	CopyArray(arr1, arr2, arr1Length, arr2Length);
	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, arr1Length);
	cout << "\nArray 2 Odd Numbers:\n";
	PrintArray(arr2, arr2Length);
}