// Shuffle Array
// https://programmingadvices.com/courses/1811531/lectures/41374844/comments/25786206

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void AddElements(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = i + 1;
}

void Shuffle(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int randIndex = RandomNumber(0, length - 1);
		int temp = arr[i];
		arr[i] = arr[randIndex];
		arr[randIndex] = temp;
	}
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
	int arr[100], length;

	cout << "Number Of Elements: ";
	cin >> length;

	AddElements(arr, length);
	cout << "\nArray Elements Before Shuffle:\n";
	PrintArray(arr, length);
	cout << "\nArray Elements After Shuffle:\n";
	Shuffle(arr, length);
	PrintArray(arr, length);
}