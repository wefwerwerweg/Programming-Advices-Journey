// Return Number Index In Array
// https://programmingadvices.com/courses/1811531/lectures/41412078/comments/25786486

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

int CheckNumInArr(int arr[], int length, int n)
{
	for (int i = 0; i < length; i++)
		if (arr[i] == n) return i;
	return -1;
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

	int arr[100], length, n;
	cout << "Number Of Elements: ";
	cin >> length;

	AddElements(arr, length);
	cout << "\nArray Elements:\n";
	PrintArray(arr, length);
	cout << "\nNumber You Are Looking For Is: ";
	cin >> n;

	int index = CheckNumInArr(arr, length, n);
	if (index != -1)
	{
		cout << "Number Is Found At Position  : " << index << endl;
		cout << "Number's Order In Array Is   : " << index + 1 << endl;
	}
	else cout << "The Number Is Not Found :-(\n";
}