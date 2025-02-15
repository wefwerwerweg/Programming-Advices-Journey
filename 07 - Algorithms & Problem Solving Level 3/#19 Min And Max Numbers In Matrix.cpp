// #19 Min And Max Numbers In Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442223/comments/25839544

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

int MinNumInMatrix(int matrix[3][3], short rows, short cols)
{
	int min = matrix[0][0];
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] < min) min = matrix[i][j];
	return min;
}

int MaxNumInMatrix(int matrix[3][3], short rows, short cols)
{
	int max = matrix[0][0];
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (matrix[i][j] > max) max = matrix[i][j];
	return max;
}


int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	FillMatrix(matrix, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nMin Number Is: " << MinNumInMatrix(matrix, 3, 3) << endl;
	cout << "\nMax Number Is: " << MaxNumInMatrix(matrix, 3, 3) << endl;

	return 0;
}
