// Return Number In Array
// https://programmingadvices.com/courses/1811531/lectures/41412888/comments/25786543

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

int CheckNumIndexInArr(int arr[], int length, int n)
{
	for (int i = 0; i < length; i++)
		if (arr[i] == n) return i;
	return -1;
}

bool CheckNumInArr(int arr[], int length, int n)
{
	return CheckNumIndexInArr(arr, length, n) != -1;
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

	if (CheckNumInArr(arr, length, n))
		cout << "The Number Is Found :-)\n";
	else 
		cout << "The Number Is Not Found :-(\n";
}