// #18 Intersected Numbers In Matrices
// https://programmingadvices.com/courses/1869980/lectures/42442222/comments/25839476

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

void PrintIntersectedNums(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
	cout << " ";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (IsNumInMatrix(matrix2, matrix1[i][j], rows, cols))
				printf("%02d\t", matrix1[i][j]);
		}
	}
	cout << endl;
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

	cout << "\nIntersected Numbers Are:\n";
	PrintIntersectedNums(matrix1, matrix2, 3, 3);

	return 0;
}
