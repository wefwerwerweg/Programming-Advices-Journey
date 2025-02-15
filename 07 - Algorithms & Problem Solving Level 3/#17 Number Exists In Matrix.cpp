// #17 Number Exists In Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442220/comments/25839418

#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			matrix[i][j] = RandomNumber(1, 100);
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		cout << " ";
		for (short j = 0; j < cols; j++)
		{
			printf("%02d\t", matrix[i][j]);
		}
		cout << endl;
	}
}

bool IsNumInMatrix(int matrix[3][3], int num, short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] == num) return true;
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3], num;
	FillMatrix(matrix, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nEnter the number to look for in the matrix: ";
	cin >> num;
	if (IsNumInMatrix(matrix, num, 3, 3))
		cout << "\nYes: It is there.\n";
	else cout << "\nNo: It is NOT there.\n";

	return 0;
}
