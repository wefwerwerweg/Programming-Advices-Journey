// #12 Check Typical Matrices
// https://programmingadvices.com/courses/1869980/lectures/42442212/comments/25839218

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

bool CheckTypicalMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix1[i][j] != matrix2[i][j]) return false;
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3];
	FillMatrix(matrix1, 3, 3);
	FillMatrix(matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix(matrix1, 3, 3);	
	cout << "\nMatrix2:\n";
	PrintMatrix(matrix2, 3, 3);

	if (CheckTypicalMatrices(matrix1, matrix2, 3, 3))
		cout << "\nYes: Matrices are typical.\n";
	else cout << "\nNo: Matrices are NOT typical.\n";
	return 0;
}
