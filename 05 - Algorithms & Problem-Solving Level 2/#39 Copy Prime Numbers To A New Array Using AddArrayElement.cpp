// Copy Prime Numbers To A New Array Using AddArrayElement
// https://programmingadvices.com/courses/1811531/lectures/41414466/comments/25787006

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
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

void AddElements(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = RandomNumber(1, 100);
}

void AddArrayElement(int num, int arr[], int& length)
{
	arr[length++] = num;
}

void CopyArray(int src[], int dest[], int srcLength, int& destLength)
{
	for (int i = 0; i < srcLength; i++)
		if (CheckPrime(src[i])) AddArrayElement(src[i], dest, destLength);
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

	int arr1[100], arr2[100], arr1Length, arr2Length = 0;
	cout << "Number Of Elements: ";
	cin >> arr1Length;
	AddElements(arr1, arr1Length);
	CopyArray(arr1, arr2, arr1Length, arr2Length);
	cout << "\nArray 1 Elements:\n";
	PrintArray(arr1, arr1Length);
	cout << "\nArray 2 Prime Numbers:\n";
	PrintArray(arr2, arr2Length);
}