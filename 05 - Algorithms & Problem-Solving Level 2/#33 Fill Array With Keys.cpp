// Fill Array With Keys
// https://programmingadvices.com/courses/1811531/lectures/41412068/comments/25786395

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

string GenerateKey()
{
	string key = "";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			key += char(RandomNumber(65, 90));

		if (i != 3) key += '-';
	}

	return key;
}

void AddElements(string arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = GenerateKey();
}

void PrintArray(string arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << "Array[" << i << "]: " << arr[i] << endl;
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string arr[100];
	int length;
	cout << "Number Of Keys To Generate: ";
	cin >> length;

	AddElements(arr, length);
	cout << "\nArray Elements\n";
	PrintArray(arr, length);
}