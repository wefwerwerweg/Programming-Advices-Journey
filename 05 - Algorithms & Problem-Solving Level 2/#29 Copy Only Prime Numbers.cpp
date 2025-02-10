// Copy Only Prime Numbers
// https://programmingadvices.com/courses/1811531/lectures/41372906/comments/25782557

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

bool CheckPrime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;

	for (int i = 3; i <= sqrt(x); i += 2)
		if (x % i == 0) return false;

	return true;
}

int CopyArray(int arr1[], int arr2[], int length)
{
	int arr2length = 0;
	for (int i = 0; i < length; i++)
	{
		if (CheckPrime(arr1[i]))
		{
			arr2[arr2length] = arr1[i];
			arr2length++;
		}
	}
	return arr2length;
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
	int arr1[100], arr2[100], arr1length, arr2length;

	cout << "Array Length: ";
	cin >> arr1length;

	AddElements(arr1, arr1length);
	arr2length = CopyArray(arr1, arr2, arr1length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, arr1length);
	cout << "\nArray 2 Of Prime Numbers:\n";
	PrintArray(arr2, arr2length);
}