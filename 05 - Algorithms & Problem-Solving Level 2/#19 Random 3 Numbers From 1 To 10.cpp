// Random 3 Numbers From 1 To 10

#include <iostream>

using namespace std;

// Function to generate a random number
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int main() {
	srand((unsigned) time(NULL));

	for (int i = 0; i < 3; i++)
		cout << RandomNumber(1, 10) << endl;
}