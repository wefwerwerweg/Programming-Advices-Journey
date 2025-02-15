// #11 Check Matrices Equality
// https://programmingadvices.com/courses/1869980/lectures/42442211/comments/25839180

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

int SumMatrix(int matrix[3][3], short rows, short cols)
{
	int sum = 0;
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			sum += matrix[i][j];
	return sum;
}

bool CheckEquality(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
	return SumMatrix(matrix1, rows, cols) == SumMatrix(matrix2, rows, cols);
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
	if (CheckEquality(matrix1, matrix2, 3, 3))
		cout << "\nYes: Matrices are equal.\n";
	else cout << "\nNo: Matrices are NOT equal.\n";
	return 0;
}
