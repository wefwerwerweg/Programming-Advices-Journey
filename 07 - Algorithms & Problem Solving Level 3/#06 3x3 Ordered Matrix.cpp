// #6 3x3 Ordered Matrix
// https://programmingadvices.com/courses/1869980/lectures/42442205/comments/25838967

#include <iostream>

using namespace std;

void FillMatrix(int matrix[3][3], short rows, short columns)
{
	short counter = 1;
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < columns; j++)
			matrix[i][j] = counter++;
}

void PrintMatrix(int matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
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
	return 0;
}
