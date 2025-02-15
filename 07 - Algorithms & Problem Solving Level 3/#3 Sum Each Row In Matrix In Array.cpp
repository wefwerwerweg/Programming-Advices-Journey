// #3 Sum Each Row In Matrix In Array

#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = RandomNumber(1, 100);
}

void PrintMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(3) << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void SumRow(int matrix[3][3], int arrSum[3], short row, short columns)
{
	int sum = 0;
	for (int i = 0; i < columns; i++)
	{
		sum += matrix[row][i];
	}
	arrSum[row] = sum;
}

void SumEachRowInMatrixToArray(int matrix[3][3], int arrSum[3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
	{
		SumRow(matrix, arrSum, i, columns);
	}
}

void PrintArraySum(int arrSum[3], short rows)
{
	for (int i = 0; i < rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3], arrSum[3];
	FillMatrix(matrix, 3, 3);
	cout << "The following is a 3x3 matrix:\n";
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nThe following are the sum of each row in the matrix:\n";
	SumEachRowInMatrixToArray(matrix, arrSum, 3, 3);
	PrintArraySum(arrSum, 3);
	return 0;
}