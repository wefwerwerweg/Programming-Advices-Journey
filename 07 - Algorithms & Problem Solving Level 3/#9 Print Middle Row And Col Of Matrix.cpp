// #9 Print Middle Row And Col Of Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442208/comments/25839091

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

void PrintMiddleRow(int matrix[3][3], short rows, short cols)
{
	short middleRow = rows / 2;
	cout << " ";
	for (short i = 0; i < cols; i++)
		printf("%02d\t", matrix[middleRow][i]);
	cout << endl;
}

void PrintMiddleCol(int matrix[3][3], short rows, short cols)
{
	short middleCol = cols / 2;
	cout << " ";
	for (short i = 0; i < rows; i++)
		printf("%02d\t", matrix[i][middleCol]);
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	int matrix[3][3];

	FillMatrix(matrix, 3, 3);
	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nMiddle row of Matrix is:\n";
	PrintMiddleRow(matrix, 3, 3);
	cout << "\n\nMiddle col of Matrix is:\n";
	PrintMiddleCol(matrix, 3, 3);
	return 0;
}