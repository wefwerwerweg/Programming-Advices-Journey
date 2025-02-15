// #10 Sum Of Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442209/comments/25839136

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

int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];

	FillMatrix(matrix, 3, 3);
	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nSum of Matrix is: " << SumMatrix(matrix, 3, 3) << endl;
	return 0;
}