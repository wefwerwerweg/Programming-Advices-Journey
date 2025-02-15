// #8 Multiply Two Matrices
// https://programmingadvices.com/courses/1869980/lectures/42442207/comments/25838997

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

void MultiplyTwoMatrices(int matrix1[3][3], int matrix2[3][3], int results[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			results[i][j] = matrix1[i][j] * matrix2[i][j];
}

int main()
{
	srand((unsigned)time(NULL));
	int matrix1[3][3], matrix2[3][3], results[3][3];

	FillMatrix(matrix1, 3, 3);
	FillMatrix(matrix2, 3, 3);
	cout << "Matrix1:\n";
	PrintMatrix(matrix1, 3, 3);
	cout << "\n\nMatrix2:\n";
	PrintMatrix(matrix2, 3, 3);
	MultiplyTwoMatrices(matrix1, matrix2, results, 3, 3);
	cout << "\n\nResults:\n";
	PrintMatrix(results, 3, 3);
	return 0;
}
