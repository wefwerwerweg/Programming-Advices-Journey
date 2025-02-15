// #7 Transpose Matrix

#include <iostream>

using namespace std;

void FillMatrix(int matrix[3][3], short rows, short cols)
{
	short counter = 1;
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			matrix[i][j] = counter++;
}

void CopyMatrix(int src[3][3], int dest[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			dest[i][j] = src[i][j];
}

void TransposeMatrix(int matrix[3][3], short rows, short cols)
{
	int temp[3][3];
	CopyMatrix(matrix, temp, rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = temp[j][i];
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int matrix[3][3];
	FillMatrix(matrix, 3, 3);
	cout << "The following is a 3x3 ordered matrix:\n";
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nThe following is the transposed matrix:\n";
	TransposeMatrix(matrix, 3, 3);
	PrintMatrix(matrix, 3, 3);
	return 0;
}