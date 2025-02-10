// Average Of Random Array
// https://programmingadvices.com/courses/1811531/lectures/41361276/comments/25782409

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

float Average(int arr[], int length)
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