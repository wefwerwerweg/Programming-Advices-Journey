// Keys Generator.
// https://programmingadvices.com/courses/1811531/lectures/41359860/comments/25779861

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
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

int main() {
	srand((unsigned)time(NULL));

	int n;
	cout << "Number Of Keys To Generate: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey() << endl;
	}
}