// Add Elements To Array Semi Dynamic
// https://programmingadvices.com/courses/1811531/lectures/41413474/comments/25786739

#include <iostream>

using namespace std;

bool AddElements(int arr[], int& length)
{
	bool more;
	cout << "\nEnter A Number: ";
	cin >> arr[length++];
	cout << "Do You Want To Add More? [0]:No [1]:Yes? ";
	cin >> more;
	if (!more) return false;
}

void PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main()
{
	int arr[100], length = 0;
	while (AddElements(arr, length));
	cout << "\nArray Length  : " << length << endl;
	cout << "Array Elements: ";
	PrintArray(arr, length);
}