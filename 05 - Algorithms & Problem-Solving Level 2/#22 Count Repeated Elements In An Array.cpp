// Count Repeated Elements In An Array.
// https://programmingadvices.com/courses/1811531/lectures/41359985/comments/25782257

#include <iostream>

using namespace std;

void AddElements(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> array[i];
	}
}

void PrintArray(int array[], int length)
{
	cout << "\nOriginal Array: ";
	for (int i = 0; i < length; i++)
		cout << array[i] << ' ';
	cout << endl;
}

int CheckFrequency(int array[], int length, int number)
{
	int frequency = 0;
	for (int i = 0; i < length; i++)
		if (array[i] == number) frequency++;
	return frequency;
}

int main()
{
	int elems[100], elemsCount, checkNumber;

	cout << "Number Of Elements: ";
	cin >> elemsCount;
	cout << "\nEnter Array Elements\n";
	AddElements(elems, elemsCount);
	cout << "\nCheck Frequency Of Number: ";
	cin >> checkNumber;
	PrintArray(elems, elemsCount);
	cout << checkNumber << " Is Repeated " << CheckFrequency(elems, elemsCount, checkNumber) << " Time(s).\n";
}