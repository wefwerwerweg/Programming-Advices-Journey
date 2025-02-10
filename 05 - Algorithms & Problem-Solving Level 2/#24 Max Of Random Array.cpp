// Max Of Random Array
// https://programmingadvices.com/courses/1811531/lectures/41360211/comments/25782347

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

void PrintArray(int arr[], int length)
{
	cout << "\nArray Elements: ";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int MaxNumber(int arr[], int length)
{
	int max = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] > max) max = arr[i];
	return max;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], length;
	cout << "Array Length: ";
	cin >> length;
	AddElements(arr, length);
	PrintArray(arr, length);
	cout << "Max Number Is: " << MaxNumber(arr, length) << endl;
}