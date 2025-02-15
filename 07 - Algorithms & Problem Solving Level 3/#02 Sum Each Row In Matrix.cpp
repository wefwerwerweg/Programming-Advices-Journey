// #2 Sum Each Row In Matrix

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

void SumEachRowInMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < columns; j++)
		{
			sum += matrix[i][j];
		}
		cout << " Row " << i + 1 << " Sum = " << sum << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];
	FillMatrix(matrix, 3, 3);
	cout << "The following is a 3x3 matrix:\n";
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nThe following are the sum of each row in the matrix:\n";
	SumEachRowInMatrix(matrix, 3, 3);
	return 0;
}