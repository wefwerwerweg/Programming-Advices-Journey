// #14 Check Scalar Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442214/comments/25839295

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

bool IsScalarMarix(int matrix[3][3], short rows, short cols)
{
	// Check that diagonal elements are 1 and rest elements are 0
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			// Check for diagonal elements
			if (i == j && matrix[i][j] != matrix[0][0])
			{
				return false;
			}
			// Check for rest elements
			else if (i != j && matrix[i][j] != 0)
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

	if (IsScalarMarix(matrix, 3, 3))
		cout << "\nYes: Matrix is scalar.\n";
	else cout << "\nNo: Matrices is NOT scalar.\n";
	return 0;
}
