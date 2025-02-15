// #13 Check Identity Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442213/comments/25839244

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
			matrix[i][j] = RandomNumber(1, 10);
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

bool IsIdentityMarix(int Matrix[3][3], short rows, short cols)
{
	// Check that diagonal elements are 1 and rest elements are 0
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			// Check for diagonal elements
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
			}
			// Check for rest elements
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	FillMatrix(matrix, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);	

	if (IsIdentityMarix(matrix, 3, 3))
		cout << "\nYes: Matrix is identity.\n";
	else cout << "\nNo: Matrices is NOT identity.\n";
	return 0;
}
